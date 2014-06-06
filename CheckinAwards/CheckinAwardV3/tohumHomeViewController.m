//
//  tohumHomeViewController.m
//  CheckinAwardV3
//
//  Created by Hamdi ALTINOK on 10.01.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumHomeViewController.h"

@interface tohumHomeViewController ()

@end

const NSString *TabBar_Checkin=@"Check In";
const NSString *TabBar_Me=@"Me";
const NSString *TabBar_Wall=@"Wall";
const NSString *TabBar_Friends=@"Friends";

@implementation tohumHomeViewController
@synthesize locationManager,latitude,longitude,companyName;
@synthesize marka;
@synthesize facebook;
@synthesize companyGENEL;
@synthesize HomeAwardPictures,HomeCompanyPictures;
static bool flag = FALSE;
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    UIBarButtonItem *nextButton = [[UIBarButtonItem alloc] initWithTitle:@"Checkin" style:UIBarButtonItemStyleBordered target:self action:@selector(goCheckin)];
    self.navigationItem.rightBarButtonItem = nextButton;
    
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
        self.tabBarItem.image = [UIImage imageNamed:@"location-pointer"];
        self.tabBarItem.title = @"Checkin";
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    [self.navigationController setNavigationBarHidden:NO animated:YES];
    //[self.navigationItem setTitle:@""];
    [self setLocationManager:[[CLLocationManager alloc] init]];
    self.marka = [[NSMutableArray alloc] init];
    self.HomeCompanyPictures = [[NSMutableArray alloc] init];
    self.HomeAwardPictures = [[NSMutableArray alloc] init];
    
    //HUD BAŞ...
    HUD = [[MBProgressHUD alloc] initWithView:self.view];
	[self.view addSubview:HUD];
	
	HUD.dimBackground = YES;
    [HUD show:YES];
    //HUD SON...
    [locationManager setDelegate:self];
    [locationManager setDistanceFilter:kCLDistanceFilterNone];
    [locationManager setDesiredAccuracy:kCLLocationAccuracyHundredMeters];
    [locationManager startUpdatingLocation];
    
    self.mapView.delegate = self;
    [self.mapView setShowsUserLocation:YES];
    
    
    if (nil == self.facebook) {
        self.facebook = [[Facebook alloc]
                         initWithAppId:@"406902399389177"
                         andDelegate:nil];
        
        // Store the Facebook session information
        self.facebook.accessToken = FBSession.activeSession.accessToken;
        self.facebook.expirationDate = FBSession.activeSession.expirationDate;
    }
    
    companyName = @"asd";
    
    flag = FALSE;
    //[self connectCheckinService];
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc]
                                              initWithTitle:@"Logout"
                                              style:UIBarButtonItemStyleBordered
                                              target:self
                                              action:@selector(logoutButtonWasPressed:)];

    
    
}
- (void)goCheckin
{
    if (flag){
        
        tohumPlistControl *control = [[tohumPlistControl alloc] init];
        NSMutableDictionary *params = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                                       @"Check in Award", @"name",
                                       [NSString stringWithFormat:@"http://www.checkinawards.com?checkin_control=true&company_id=%@&user_name=%@",companyGENEL.ID_,[control getUserNAME]], @"link",
                                       companyGENEL.CompanyName, @"caption",
                                       companyGENEL.CompanyCampaign.CampaignText, @"description",
                                       companyGENEL.CompanyImageURL,@"picture",
                                       @"Checkin Awards", @"message",
                                       nil];
        
        // Invoke the dialog
        [self.facebook dialog:@"feed" andParams:params andDelegate:self];
        
    }
    else {
        UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Warning"
                                                          message:@"Please choose a restaurant first!"
                                                         delegate:nil
                                                cancelButtonTitle:@"OK"
                                                otherButtonTitles:nil];
        [message show];
    }

}

-(void)logoutButtonWasPressed:(id)sender {
    [FBSession.activeSession closeAndClearTokenInformation];
    tohumAppDelegate *objAppDelegate=(tohumAppDelegate *)[[UIApplication sharedApplication] delegate];
    
    tohumViewController *viewController = [[tohumViewController alloc] initWithNibName:@"tohumViewController" bundle:nil];
    
    [objAppDelegate.navController3 presentViewController:viewController animated:YES completion:nil];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (NSDictionary*)parseURLParams:(NSString *)query {
    NSArray *pairs = [query componentsSeparatedByString:@"&"];
    NSMutableDictionary *params = [[NSMutableDictionary alloc] init];
    for (NSString *pair in pairs) {
        NSArray *kv = [pair componentsSeparatedByString:@"="];
        NSString *val =
        [[kv objectAtIndex:1]
         stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        
        [params setObject:val forKey:[kv objectAtIndex:0]];
    }
    return params;
}
- (void)dialogCompleteWithUrl:(NSURL *)url {
    
    //NSLog(@"didSelectItem: %d", item.tag);
    tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
    CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
    tohumPlistControl *control = [[tohumPlistControl alloc] init];
    
    CheckinAward_Checkin *checkIn = [[CheckinAward_Checkin alloc] init];
    checkIn.CompanyID = companyGENEL.ID_;
    checkIn.UserID =  [[NSNumber alloc] initWithInteger:[[control getUserNAME] integerValue]];
    
    [binding CheckinAsyncUsingParameters:checkIn delegate:self];
    
    //NSDictionary *params = [self parseURLParams:[url query]];
    //NSString *msg = [NSString stringWithFormat:
    //                 @"Posted story, id: %@",
    //                 [params valueForKey:@"post_id"]];
    //NSLog(@"%@", msg);
    // Show the result in an alert
    [[[UIAlertView alloc] initWithTitle:@"Check-in Awards"
                                message:[NSString stringWithFormat:@"Successfully checked in at %@",companyGENEL.CompanyName]
                               delegate:nil
                      cancelButtonTitle:@"OK!"
                      otherButtonTitles:nil]
     show];
}
- (IBAction)publishButtonAction:(id)sender {
    // Put together the dialog parameters
    // Create the parameters dictionary that will keep the data that will be posted.
    NSMutableDictionary *params = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                                   @"Check in Award", @"name",
                                   @"http://www.google.com", @"link",
                                   companyGENEL.CompanyName, @"caption",
                                   companyGENEL.CompanyCampaign.CampaignText, @"description",
                                   @"Hello!\n\nThis is a test message\nfrom my test iPhone app!", @"message",
                                   nil];
    
    // Invoke the dialog
    [self.facebook dialog:@"feed" andParams:params andDelegate:self];
}

- (void)locationManager:(CLLocationManager *)manager
    didUpdateToLocation:(CLLocation *)newLocation fromLocation:(CLLocation *)oldLocation {
    
    
    NSLog(@"ValueX: %f", newLocation.coordinate.latitude);
    NSLog(@"ValueY: %f", newLocation.coordinate.longitude);
    latitude = [[NSNumber alloc] initWithDouble:newLocation.coordinate.latitude];
    
    longitude = [[NSNumber alloc] initWithDouble:newLocation.coordinate.longitude];
    
    [locationManager stopUpdatingLocation];
    [self connectCheckinService];
}


- (void) connectCheckinService {

    [HUD show:YES];
    
    tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
    CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
    
    CheckinAward_GetCompaniesNearby *companies = [[CheckinAward_GetCompaniesNearby alloc] init];
    CheckinAward_LatLng *LatLng = [[CheckinAward_LatLng alloc] init];
    LatLng.C_X = latitude;
    LatLng.C_Y = longitude;
    
    companies.Coordinates = LatLng;
    companies.maxCount = [[NSNumber alloc] initWithInt:10];
    
    [binding GetCompaniesNearbyAsyncUsingParameters:companies delegate:self];
    
}
- (void) operation:(CheckinAwardSoap12BindingOperation *)operation completedWithResponse:(CheckinAwardSoap12BindingResponse *)response{

    
    for (id mine in response.bodyParts){
        if ([mine isKindOfClass:[CheckinAward_GetCompaniesNearbyResponse class]]){
            //Table view refresh
            [self.marka removeAllObjects];
            [_locationTABLE reloadData];
            if ([mine GetCompaniesNearbyResult] != NULL)
            {
                NSLog(@"Yakın yerler geldi : %@",[mine GetCompaniesNearbyResult]);
                id getNearby = [mine GetCompaniesNearbyResult];
                id company = [getNearby Company];
                for (id comp in company){
                    
                    NSLog(@"Company Name%@",[comp CompanyName]);
                    id campaing = [comp CompanyCampaign];
                    id coordinates = [comp Coordinates];
                    
                    CheckinAward_Company *company = [[CheckinAward_Company alloc] init];
                    company.CompanyName = [comp CompanyName];
                    company.CompanyImageURL = [comp CompanyImageURL];
                    company.ID_ = [comp ID_];
                    
                    CheckinAward_Campaign *Campaing = [[CheckinAward_Campaign alloc] init];
                    Campaing.CampaignText = [campaing CampaignText];
                    Campaing.CampaignImageURL = [campaing CampaignImageURL];
                    company.CompanyCampaign = Campaing;
                    
                    CheckinAward_LatLng *Coordinates = [[CheckinAward_LatLng alloc] init];
                    Coordinates.C_X = [coordinates C_X];
                    Coordinates.C_Y = [coordinates C_Y];
                    //Coordinates.C_X = [NSNumber numberWithDouble:38.393314];
                    //Coordinates.C_Y = [NSNumber numberWithDouble:27.151730];
                    company.Coordinates = Coordinates;
                    
                    [self.marka addObject:company];
                    
                    //Marka resmini yerleştirme
                    if (company.CompanyImageURL != NULL)
                    {
                        NSURL * imageURL = [NSURL URLWithString:company.CompanyImageURL];
                        NSData * imageData = [NSData dataWithContentsOfURL:imageURL];
                        [self.HomeCompanyPictures addObject:[UIImage imageWithData:imageData]];
                    }
                    
                    //Kampanya resmini yerleştirme
                    if (company.CompanyCampaign.CampaignImageURL != NULL)
                    {
                        NSURL * imageURL = [NSURL URLWithString:company.CompanyCampaign.CampaignImageURL];
                        NSData * imageData = [NSData dataWithContentsOfURL:imageURL];
                        [self.HomeAwardPictures addObject:[UIImage imageWithData:imageData]];
                    }else {
                        [self.HomeAwardPictures addObject:[UIImage imageNamed:@"award"]];
                    }

                    
                    
                    //Add Marker...
                    CLLocationCoordinate2D annotationCoord;
                    
                    annotationCoord.latitude = [company.Coordinates.C_X doubleValue];
                    annotationCoord.longitude = [company.Coordinates.C_Y doubleValue];
                    
                    MKPointAnnotation *annotationPoint = [[MKPointAnnotation alloc] init];
                    annotationPoint.coordinate = annotationCoord;
                    annotationPoint.title = company.CompanyName;
                    annotationPoint.subtitle = company.CompanyCampaign.CampaignText;
                    
                    [self.mapView addAnnotation:annotationPoint];

                }
                
                [_locationTABLE reloadData];
                
            }
            else
            {

            }
        }
        else if ([mine isKindOfClass:[CheckinAward_CheckinResponse class]])
        {
            if ([mine CheckinResult] != NULL)
            {
                NSLog(@"Checkin Result");
                id checkinResult = [mine CheckinResult];
                Boolean checkinSuccess = [[checkinResult CA_CheckinSuccess] boolValue];
                if (checkinSuccess){
                    Boolean checkinAward =[[checkinResult CA_IsAwarded] boolValue];
                    NSLog(@"isaward: %d",checkinAward);
                    if (checkinAward){
                        
                        NSString *awardCode = [checkinResult CA_AwardCode];
                        NSLog(@"awardcode: %@",awardCode);
                        [[[UIAlertView alloc] initWithTitle:@"Congratulations!"
                                                    message:[NSString stringWithFormat:@"You won a prize from %@.\nGet your prize using '%@' code.\nAlso, this code was send to your email.",companyGENEL.CompanyName,awardCode]
                                                   delegate:nil
                                          cancelButtonTitle:@"OK!"
                                          otherButtonTitles:nil]
                         show];
                    }
                }
            }
        }
    }
    [HUD hide:YES];
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    
    
    return [self.marka count];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    return 60;
}
- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath{
    //put data on your array
    //[tableView reloadData];
    
    
    
    NSLog(@"%d", [indexPath row]);
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *simpleTableIdentifier = @"CustomCell";
    
    NSLog(@"%d", [indexPath row]);
    
    tohumCustomCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    
    CheckinAward_Company *company = [self.marka objectAtIndex:[indexPath row]];
    
    if (cell == nil) {
        NSArray *nib = [[NSBundle mainBundle] loadNibNamed:@"CustomCell" owner:self options:nil];
        for(id currentObject in nib)
        {
            if([currentObject isKindOfClass:[tohumCustomCell class]])
            {
                cell = (tohumCustomCell *)currentObject;
                break;
            }
        }
        
    }
    cell.markaNAME.text = company.CompanyName;
    //Marka resmini yerleştirme
    if ([indexPath row] < [self.HomeAwardPictures count]){
    
        cell.markaIMAGE.image = [self.HomeCompanyPictures objectAtIndex:[indexPath row]];
        cell.awardIMAGE.image = [self.HomeAwardPictures objectAtIndex:[indexPath row]];
    }
    
    if (company.CompanyCampaign.CampaignText != NULL)
        cell.markaLABEL1.text = company.CompanyCampaign.CampaignText;
    else
        cell.markaLABEL1.text = @"Any campaign was not found.";
    return cell;
}

//Table view row selection
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    //table da seçim yapılıp yapıladığını kontrol eder
    flag = TRUE;
    
    companyGENEL = [self.marka objectAtIndex:indexPath.row];
    NSLog(@"Company Name%@",companyGENEL.CompanyName);
    NSLog(@"C_X: %@",companyGENEL.Coordinates.C_X);
    NSLog(@"Company ID: %@",companyGENEL.ID_);
    tohumPlistControl *control = [[tohumPlistControl alloc] init];
    NSLog(@"User ID: %@",[control getUserNAME]);
    
}
#pragma mark - MKMapViewDelegate methods.
- (void)mapView:(MKMapView *)mv didAddAnnotationViews:(NSArray *)views {
    MKCoordinateRegion region;
    region = MKCoordinateRegionMakeWithDistance(locationManager.location.coordinate,1000,1000);
    
    
    [mv setRegion:region animated:YES];
}
-(MKAnnotationView *)mapView:(MKMapView *)mV viewForAnnotation:(id <MKAnnotation>)annotation
{
    MKAnnotationView *pinView = nil;
    if(annotation != self.mapView.userLocation)
    {
        static NSString *defaultPinID = @"com.checkinawards.pin";
        pinView = (MKAnnotationView *)[self.mapView dequeueReusableAnnotationViewWithIdentifier:defaultPinID];
        if ( pinView == nil )
            pinView = [[MKAnnotationView alloc]
                       initWithAnnotation:annotation reuseIdentifier:defaultPinID];
        
        //pinView.pinColor = MKPinAnnotationColorGreen;
        pinView.canShowCallout = YES;
        //pinView.animatesDrop = YES;
        pinView.image = [UIImage imageNamed:@"Map_pin2.png"];
    }
    else {
        [self.mapView.userLocation setTitle:@"I am here"];
    }
    return pinView;
}

- (void) setTabbarItems{
    
    
    tohumPlistControl *control = [[tohumPlistControl alloc] init];
    
    tohumHomeViewController *homeView = [[tohumHomeViewController alloc] initWithNibName:@"tohumHomeViewController" bundle:nil];
    
    tohumProfileViewController *profileView = [[tohumProfileViewController alloc] initWithNibName:@"tohumProfileViewController" bundle:nil];
    profileView.friendID = [control getUserIDnumber];
    
    tohumFriendsADDViewController *addFriendsView = [[tohumFriendsADDViewController alloc] initWithNibName:@"tohumFriendsADDViewController" bundle:nil];
    
    tohumMeWallViewController *meWallView = [[tohumMeWallViewController alloc] initWithNibName:@"tohumMeWallViewController" bundle:nil];
    
    
    self.navController = [[UINavigationController alloc] initWithRootViewController:profileView];
    UINavigationBar *navBar = [[self navController] navigationBar];
    [navBar setBarStyle:UIBarStyleBlackOpaque];
    
    self.navController2 = [[UINavigationController alloc] initWithRootViewController:addFriendsView];
    UINavigationBar *navBar2 = [[self navController2] navigationBar];
    [navBar2 setBarStyle:UIBarStyleBlackOpaque];
    
    self.navController3 = [[UINavigationController alloc] initWithRootViewController:homeView];
    UINavigationBar *navBar3 = [[self navController3] navigationBar];
    [navBar3 setBarStyle:UIBarStyleBlackOpaque];
    
    self.tabController = [[UITabBarController alloc] init];
    self.tabController.viewControllers = [NSArray arrayWithObjects:self.navController3,meWallView,self.navController,self.navController2, nil];
}

- (void)dealloc {
    [_locationTABLE release];
    [_viewCheckin release];
    [super dealloc];
}
@end
