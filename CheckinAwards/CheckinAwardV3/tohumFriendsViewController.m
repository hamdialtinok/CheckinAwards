//
//  tohumFriendsViewController.m
//  checkin awards
//
//  Created by Hamdi ALTINOK on 13.03.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumFriendsViewController.h"

@interface tohumFriendsViewController ()

@end


@implementation tohumFriendsViewController
@synthesize wallArray;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
        [self.navigationItem setTitle:@"All Friends"];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.wallArray = [[NSMutableArray alloc] init];
    pagingTokenFr = 1;
    objectCountFr = 0;
    //HUD BAŞ...
    HUD = [[MBProgressHUD alloc] initWithView:self.navigationController.view];
	[self.navigationController.view addSubview:HUD];
	
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

- (void)dealloc {
    [_wallTABLE release];
    [super dealloc];
}

//Table view row selection
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    //table da seçim yapılıp yapıladığını kontrol eder
    NSLog(@"Table view tıklandı");
    
    CheckinAward_User *user = [self.wallArray objectAtIndex:[indexPath row]];
    
    if ([user.ID_ isEqualToNumber:[NSNumber numberWithInt:-1]]){
    
        [self.wallArray removeObjectAtIndex:[indexPath row]];
        [HUD show:YES];
        
        pagingTokenFr += 1;
        [self connectCheckinService:pagingTokenFr];
    }else {
    
    
    tohumProfileViewController * profileView= [[tohumProfileViewController alloc] initWithNibName:@"tohumProfileViewController" bundle:nil];
    profileView.isFriend = [user IsFriend];
    profileView.friendID = [user ID_];
    [profileView setTitle:[user name]];
    tohumAppDelegate *objAppDelegate=(tohumAppDelegate *)[[UIApplication sharedApplication] delegate];
    [objAppDelegate.navController pushViewController:profileView animated:YES];
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

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *simpleTableIdentifier = @"FriendsCustomCell";
    
    tohumFriendsCustomCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    
    //CheckinAward_CA_PersonalCheckin *personalCheckin = [self.wallArray objectAtIndex:[indexPath row]];
    
    CheckinAward_User *user = [self.wallArray objectAtIndex:[indexPath row]];
    
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
        
        /*NSDate *date = personalCheckin.CheckInDate;
        NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
        [dateFormat setDateFormat:@"dd-MM-yyyy HH:mm"];
        
        //NSLog(@"%@", [dateFormat stringFromDate:date]);
        
        
        cell.AwardsDetail.text = personalCheckin.CA_CheckedInCompany.CompanyName;
        cell.userName.text = personalCheckin.CA_CheckedInUser.name;
        cell.CommentsLabel.text = personalCheckin.CA_CheckedInCompany.CompanyCampaign.CampaignText;
        cell.dateLabel.text = [dateFormat stringFromDate:date];
        
        if (personalCheckin.CA_CheckedInCompany.CompanyImageURL != NULL)
        {
            NSURL * imageURL = [NSURL URLWithString:personalCheckin.CA_CheckedInCompany.CompanyImageURL];
            NSData * imageData = [NSData dataWithContentsOfURL:imageURL];
            cell.AwardsPicture.image = [UIImage imageWithData:imageData];
        }
        
        if (personalCheckin.CA_CheckedInUser.CA_personPhotoUrl != NULL)
        {
            //picture BAŞ...
            [Base64 initialize];
            NSString *str = personalCheckin.CA_CheckedInUser.CA_personPhotoUrl;
            NSData * data = [Base64 decode:str];
            cell.userPicture.image = [UIImage imageWithData:data];
            //Picture SON...
        }*/
        
        
        
    }
    
    if (user.CA_personPhotoUrl != NULL)
    {
        //picture BAŞ...
        [Base64 initialize];
        NSString *str = user.CA_personPhotoUrl;
        NSData * data = [Base64 decode:str];
        cell.userPicture.image = [UIImage imageWithData:data];
        //Picture SON...
    }else {
        cell.userPicture.image = [UIImage imageNamed:@"default_profile.jpg"];
    }
    cell.userName.text = [NSString stringWithFormat:@"%@ %@",user.name,user.surname];
    cell.AwardsPicture.image = NULL;
    cell.AwardsDetail.text = NULL;
    cell.dateLabel.text = NULL;
    cell.CommentsLabel.text = NULL;
  
    if ([user.ID_ isEqualToNumber:[NSNumber numberWithInt:-1]]){
        cell.userPicture.image = Nil;
        cell.AwardsPicture.image = Nil;
    }
    
    return cell;
}

- (void) connectCheckinService:(NSInteger) token{
    
    
    tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
    CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
    tohumPlistControl *control = [[tohumPlistControl alloc] init];
    
    /*CheckinAward_SelfWall *wall = [[CheckinAward_SelfWall alloc] init];
    
    wall.ownerUserID = [control getUserIDnumber];
    //checkins.CA_userID = [NSNumber numberWithInt:6];
    wall.token = [NSNumber numberWithInt:1];
    
    [binding SelfWallAsyncUsingParameters:wall delegate:self];*/
    
    CheckinAward_GetAllFriends *friends = [[CheckinAward_GetAllFriends alloc] init];
    friends.ownerUserID = [control getUserIDnumber];
    friends.token = [NSNumber numberWithInt:token];
    
    [binding GetAllFriendsAsyncUsingParameters:friends delegate:self];
    
}

- (void) operation:(CheckinAwardSoap12BindingOperation *)operation completedWithResponse:(CheckinAwardSoap12BindingResponse *)response{
    
    for (id mine in response.bodyParts){
        if ([mine isKindOfClass:[CheckinAward_SelfWallResponse class]]){
            
            id selfWallResult = [mine SelfWallResult];
            id checkinCollection = [selfWallResult CA_CheckInCollection];
            id arrayCheckin = [checkinCollection CA_PersonalCheckin];
            
            for (id item in arrayCheckin){
            
                CheckinAward_CA_PersonalCheckin *personalCheckins = [[CheckinAward_CA_PersonalCheckin alloc] init];
                
                personalCheckins.CA_CheckedInCompany = [item CA_CheckedInCompany];
                personalCheckins.CA_CheckedInUser = [item CA_CheckedInUser];
                personalCheckins.CheckInDate = [item CheckInDate];
                
                [self.wallArray addObject:personalCheckins];

            }
            [self.wallTABLE reloadData];
        }
        else if ([mine isKindOfClass:[CheckinAward_GetAllFriendsResponse class]]){
        
            id personResult = [mine GetAllFriendsResult];
            id people = [personResult CA_People];
            id user = [people User];
            
            objectCountFr = [[personResult CA_PersonCount] integerValue];
            
            for (id comp in user){
                CheckinAward_User *person = [[CheckinAward_User alloc] init];
                person = comp;
                
                [self.wallArray addObject:person];
                
                [self.wallTABLE reloadData];
            }
            if (objectCountFr == 10){
                
                CheckinAward_User *user = [[CheckinAward_User alloc] init];
                user.name = @"Load More...";
                user.ID_ = [NSNumber numberWithInt:-1];
                [self.wallArray addObject:user];
                [self.wallTABLE reloadData];
            }
            
        }
    }
    
    [HUD hide:YES];
}

@end
