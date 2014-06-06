//
//  tohumMeWallViewController.m
//  checkin awards
//
//  Created by Hamdi ALTINOK on 19.03.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumMeWallViewController.h"

@interface tohumMeWallViewController ()
@end

NSInteger countTable = 0;
NSInteger pagingToken = 1;
NSInteger objectCount = 0;

@implementation tohumMeWallViewController
@synthesize wallArray,WallAwardPictures,WallUserPictures;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
        self.tabBarItem.image = [UIImage imageNamed:@"home"];
        self.tabBarItem.title = @"Wall";
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.wallArray = [[NSMutableArray alloc] init];
    self.WallUserPictures = [[NSMutableArray alloc] init];
    self.WallAwardPictures = [[NSMutableArray alloc] init];
    
    //HUD BAŞ...
    HUD = [[MBProgressHUD alloc] initWithView:self.view];
	[self.view addSubview:HUD];
	
	HUD.dimBackground = YES;
    [HUD show:YES];
    //HUD SON...
    
    [self connectCheckinService:1];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
//Table view row selection
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    //table da seçim yapılıp yapıladığını kontrol eder
    NSLog(@"Table view tıklandı");
    
    CheckinAward_CA_PersonalCheckin *personalCheckin = [self.wallArray objectAtIndex:[indexPath row]];
    
    if ([personalCheckin.CA_CheckedInUser.ID_ isEqualToNumber:[NSNumber numberWithInt:-1]]){
        [self.wallArray removeObjectAtIndex:[indexPath row]];
        [HUD show:YES];
        
        pagingToken += 1;
        [self connectCheckinService:pagingToken];
    }
    
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.wallArray count];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 70;
}

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath{
    //put data on your array
    //[tableView reloadData];
    /*if ([indexPath row] == (pagingToken*10 - 6)){
        
        if (countTable == 1 && objectCount > 0){
            
            NSLog(@"oldu");
            NSLog(@"%d", [indexPath row]);
            countTable = 0;
            pagingToken += 1;
            [self connectCheckinService:pagingToken];
        }
        countTable = 1;
    }*/
    
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *simpleTableIdentifier = @"FriendsCustomCell";
    
    tohumFriendsCustomCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    
    CheckinAward_CA_PersonalCheckin *personalCheckin = [self.wallArray objectAtIndex:[indexPath row]];
    NSLog(@"%d",[indexPath row]);
    
    if (cell == nil) {
        NSArray *nib = [[NSBundle mainBundle] loadNibNamed:@"FriendsCustomCell" owner:self options:nil];
        for(id currentObject in nib)
        {
            if([currentObject isKindOfClass:[tohumFriendsCustomCell class]])
            {
                cell = (tohumFriendsCustomCell *)currentObject;
                break;
            }
        }
        
        
    }
    
    NSDate *date = personalCheckin.CheckInDate;
    NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
    [dateFormat setDateFormat:@"dd-MM-yyyy HH:mm"];
    
    //NSLog(@"%@", [dateFormat stringFromDate:date]);
    
    
    cell.AwardsDetail.text = personalCheckin.CA_CheckedInCompany.CompanyName;
    cell.userName.text = personalCheckin.CA_CheckedInUser.name;
    cell.CommentsLabel.text = personalCheckin.CA_CheckedInCompany.CompanyCampaign.CampaignText;
    cell.dateLabel.text = [dateFormat stringFromDate:date];
    
    if ([indexPath row]< [self.WallAwardPictures count]){
        
        cell.AwardsPicture.image = [self.WallAwardPictures objectAtIndex:[indexPath row]];
        cell.userPicture.image = [self.WallUserPictures objectAtIndex:[indexPath row]];
    }
    
    /*if (personalCheckin.CA_CheckedInCompany.CompanyImageURL != NULL)
    {
        NSURL * imageURL = [NSURL URLWithString:personalCheckin.CA_CheckedInCompany.CompanyImageURL];
        NSData * imageData = [NSData dataWithContentsOfURL:imageURL];
        cell.AwardsPicture.image = [UIImage imageWithData:imageData];
    }
    else {
        cell.AwardsPicture.image = [UIImage imageNamed:@"award"];
    }
    
    if (personalCheckin.CA_CheckedInUser.CA_personPhotoUrl != NULL)
    {
        //picture BAŞ...
        [Base64 initialize];
        NSString *str = personalCheckin.CA_CheckedInUser.CA_personPhotoUrl;
        NSData * data = [Base64 decode:str];
        cell.userPicture.image = [UIImage imageWithData:data];
        //Picture SON...
    }
    else {
    
        cell.userPicture.image = [UIImage imageNamed:@"default_profile.jpg"];
    }*/
    
    if ([personalCheckin.CA_CheckedInUser.ID_ isEqualToNumber:[NSNumber numberWithInt:-1]]){
        cell.userPicture.image = Nil;
        cell.AwardsPicture.image = Nil;
    }
    
    
    
    return cell;
}

- (void) connectCheckinService:(NSInteger) token{
    
    
    tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
    CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
    tohumPlistControl *control = [[tohumPlistControl alloc] init];
    
    CheckinAward_SelfWall *wall = [[CheckinAward_SelfWall alloc] init];
     
     wall.ownerUserID = [control getUserIDnumber];
     //checkins.CA_userID = [NSNumber numberWithInt:6];
     wall.token = [NSNumber numberWithInt:token];
     
     [binding SelfWallAsyncUsingParameters:wall delegate:self];
    
}

- (void) operation:(CheckinAwardSoap12BindingOperation *)operation completedWithResponse:(CheckinAwardSoap12BindingResponse *)response{
    
    for (id mine in response.bodyParts){
        if ([mine isKindOfClass:[CheckinAward_SelfWallResponse class]]){
            
            id selfWallResult = [mine SelfWallResult];
            id checkinCollection = [selfWallResult CA_CheckInCollection];
            id arrayCheckin = [checkinCollection CA_PersonalCheckin];
            
            objectCount = [[selfWallResult CA_objectCount] integerValue];
            
            for (id item in arrayCheckin){
                
                CheckinAward_CA_PersonalCheckin *personalCheckins = [[CheckinAward_CA_PersonalCheckin alloc] init];
                
                personalCheckins.CA_CheckedInCompany = [item CA_CheckedInCompany];
                personalCheckins.CA_CheckedInUser = [item CA_CheckedInUser];
                personalCheckins.CheckInDate = [item CheckInDate];
                
                NSLog(@"%@",personalCheckins.CA_CheckedInUser.userName);
                
                [self.wallArray addObject:personalCheckins];
                
                if (personalCheckins.CA_CheckedInCompany.CompanyImageURL != NULL)
                {
                    NSURL * imageURL = [NSURL URLWithString:personalCheckins.CA_CheckedInCompany.CompanyImageURL];
                    NSData * imageData = [NSData dataWithContentsOfURL:imageURL];
                    [self.WallAwardPictures addObject:[UIImage imageWithData:imageData]];
                }else {
                    [self.WallAwardPictures addObject:[UIImage imageNamed:@"award"]];
                }
                
                if (personalCheckins.CA_CheckedInUser.CA_personPhotoUrl != NULL)
                {
                    //picture BAŞ...
                    [Base64 initialize];
                    NSString *str = personalCheckins.CA_CheckedInUser.CA_personPhotoUrl;
                    NSData * data = [Base64 decode:str];
                    [self.WallUserPictures addObject:[UIImage imageWithData:data]];
                    //Picture SON...
                }else {
                    [self.WallUserPictures addObject:[UIImage imageNamed:@"default_profile.jpg"]];
                }
                
                [self.wallTABLE reloadData];
                
            }
            
            if (objectCount == 10){
            
                CheckinAward_CA_PersonalCheckin *personalCheckins = [[CheckinAward_CA_PersonalCheckin alloc] init];
                
                CheckinAward_User *user = [[CheckinAward_User alloc] init];
                user.name = @"Load More...";
                user.ID_ = [NSNumber numberWithInt:-1];
                personalCheckins.CA_CheckedInUser = user;
                [self.wallArray addObject:personalCheckins];
                [self.wallTABLE reloadData];
            }
        }
    }
    
    [HUD hide:YES];
}


@end
