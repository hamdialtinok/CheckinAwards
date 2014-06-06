//
//  tohumProfileViewController.m
//  checkin awards
//
//  Created by Hamdi ALTINOK on 13.03.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumProfileViewController.h"

@interface tohumProfileViewController ()

@end

@implementation tohumProfileViewController
@synthesize meWallArray,meWallDictionary,isFriend,friendID,meWallAwardPictures,meWallUserPictures;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    UIBarButtonItem *nextButton = [[UIBarButtonItem alloc] initWithTitle:@"Refresh" style:UIBarButtonItemStyleBordered target:self action:@selector(goRefresh)];
    self.navigationItem.rightBarButtonItem = nextButton;
    
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
        self.tabBarItem.image = [UIImage imageNamed:@"user kopya"];
        [self.tabBarItem setTitle:@"Me"];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.meWallArray = [[NSMutableArray alloc] init];
    self.meWallDictionary = [[NSMutableArray alloc] init];
    self.meWallUserPictures = [[NSMutableArray alloc] init];
    self.meWallAwardPictures = [[NSMutableArray alloc] init];
    pagingTokenPr = 1;
    objectCountPr = 0;
    tohumPlistControl *control = [[tohumPlistControl alloc] init];
    if (![self.friendID isEqualToNumber:[control getUserIDnumber]]){
    
        [_editProfileButton setHidden:YES];
        [_editProfileLAbel setHidden:YES];
        
        if (![self.isFriend boolValue])
        [_showFriendsButton setTitle:@"Add as Friend" forState:UIControlStateNormal];
        else
        [_showFriendsButton setTitle:@"Remove from Friends" forState:UIControlStateNormal];
            
    }
    HUD = [[MBProgressHUD alloc] initWithView:self.view];
	[self.view addSubview:HUD];
	
	HUD.dimBackground = YES;
    
    [self getPersonalInfo:self.friendID];
    [self connectCheckinService:self.friendID];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {
    [_meWallTable release];
    [_userPicture release];
    [_userNameLabel release];
    [_userCityLabel release];
    [_editProfileButton release];
    [_showFriendsButton release];
    [_editProfileLAbel release];
    [super dealloc];
}

//Table view row selection
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    //table da seçim yapılıp yapıladığını kontrol eder
    NSLog(@"Table view tıklandı");
    
    CheckinAward_CA_PersonalCheckin *personalCheckin = [self.meWallArray objectAtIndex:[indexPath row]];
    if ([personalCheckin.CA_CheckedInUser.ID_ isEqualToNumber:[NSNumber numberWithInt:-1]]){
    
        [self.meWallArray removeObjectAtIndex:[indexPath row]];
        [HUD show:YES];
        
        pagingTokenPr += 1;
        [self connectCheckinService:self.friendID];
    }
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.meWallArray count];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 70;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *simpleTableIdentifier = @"FriendsCustomCell";
    
    tohumFriendsCustomCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    
    CheckinAward_CA_PersonalCheckin *personalCheckin = [self.meWallArray objectAtIndex:[indexPath row]];
    
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
    
    if ([indexPath row]< [self.meWallAwardPictures count]){
    
        cell.AwardsPicture.image = [self.meWallAwardPictures objectAtIndex:[indexPath row]];
        cell.userPicture.image = [self.meWallUserPictures objectAtIndex:[indexPath row]];
    }
    
    /*if (personalCheckin.CA_CheckedInCompany.CompanyImageURL == NULL)
    {
        NSURL * imageURL = [NSURL URLWithString:personalCheckin.CA_CheckedInCompany.CompanyImageURL];
        NSData * imageData = [NSData dataWithContentsOfURL:imageURL];
        cell.AwardsPicture.image = [UIImage imageWithData:imageData];
    }else {
        cell.AwardsPicture.image = [UIImage imageNamed:@"award"];
    }
    
    if (personalCheckin.CA_CheckedInUser.CA_personPhotoUrl == NULL)
    {
        //picture BAŞ...
        [Base64 initialize];
        NSString *str = personalCheckin.CA_CheckedInUser.CA_personPhotoUrl;
        NSData * data = [Base64 decode:str];
        cell.userPicture.image = [UIImage imageWithData:data];
        //Picture SON...
    }else {
        
        cell.userPicture.image = [UIImage imageNamed:@"default_profile.jpg"];
    }*/

    if ([personalCheckin.CA_CheckedInUser.ID_ isEqualToNumber:[NSNumber numberWithInt:-1]]){
        cell.userPicture.image = Nil;
        cell.AwardsPicture.image = Nil;
    }
   
    return cell;
}
- (void) getPersonalInfo:(NSNumber*) userID_ {
    
    /*[Base64 initialize];
     NSData * data = [Base64 decode:@"SGVsbG8gV29ybGQ="];
     NSString * actualString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
     NSLog(@"%@",actualString);
     [actualString release];
     
     [Base64 initialize];
     _userPicture.image = [UIImage imageWithData:data];*/
    
    tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
    CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
    tohumPlistControl *control = [[tohumPlistControl alloc] init];
    
    CheckinAward_GetPersonalInfo *user = [[CheckinAward_GetPersonalInfo alloc] init];
    
    user.userID =userID_;
    user.owneruserID = [control getUserIDnumber];
        
    [binding GetPersonalInfoAsyncUsingParameters:user delegate:self];
    
}

- (void) connectCheckinService:(NSNumber*) userID_ {
    
    /*[Base64 initialize];
    NSData * data = [Base64 decode:@"SGVsbG8gV29ybGQ="];
    NSString * actualString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    NSLog(@"%@",actualString);
    [actualString release];
    
    [Base64 initialize];
    _userPicture.image = [UIImage imageWithData:data];*/
    
    tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
    CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
    
    
    CheckinAward_CA_GetPersonalCheckins *checkins = [[CheckinAward_CA_GetPersonalCheckins alloc] init];
    
    checkins.CA_userID = userID_;
    //checkins.CA_userID = [NSNumber numberWithInt:6];
    checkins.CA_pagingToken = [NSNumber numberWithInt:pagingTokenPr];
        
    [binding CA_GetPersonalCheckinsAsyncUsingParameters:checkins delegate:self];
    
}
- (void) operation:(CheckinAwardSoap12BindingOperation *)operation completedWithResponse:(CheckinAwardSoap12BindingResponse *)response{
    
    
    for (id mine in response.bodyParts){
        if ([mine isKindOfClass:[CheckinAward_CA_GetPersonalCheckinsResponse class]]){
            
            id checkinResult = [mine CA_GetPersonalCheckinsResult];
            id checkinCollection = [checkinResult CA_CheckInCollection];
            id arrayCehckin = [checkinCollection CA_PersonalCheckin];
            
            objectCountPr = [[checkinResult CA_objectCount] integerValue];
            
            for (id comp in arrayCehckin){
                CheckinAward_CA_PersonalCheckin *personalCheckins = [[CheckinAward_CA_PersonalCheckin alloc] init];
                
                //id personalCheckin = [comp CA_PersonalCheckin];
                personalCheckins.CA_CheckedInCompany = [comp CA_CheckedInCompany];
                personalCheckins.CA_CheckedInUser = [comp CA_CheckedInUser];
                personalCheckins.CheckInDate = [comp CheckInDate];

                [self.meWallArray addObject:personalCheckins];
                [self.meWallDictionary addObject:[comp ID_]];
                
                if (personalCheckins.CA_CheckedInCompany.CompanyImageURL != NULL)
                {
                    NSURL * imageURL = [NSURL URLWithString:personalCheckins.CA_CheckedInCompany.CompanyImageURL];
                    NSData * imageData = [NSData dataWithContentsOfURL:imageURL];
                    [self.meWallAwardPictures addObject:[UIImage imageWithData:imageData]];
                }else {
                    [self.meWallAwardPictures addObject:[UIImage imageNamed:@"award"]];
                }
                
                if (personalCheckins.CA_CheckedInUser.CA_personPhotoUrl != NULL)
                {
                    //picture BAŞ...
                    [Base64 initialize];
                    NSString *str = personalCheckins.CA_CheckedInUser.CA_personPhotoUrl;
                    NSData * data = [Base64 decode:str];
                    [self.meWallUserPictures addObject:[UIImage imageWithData:data]];
                    //Picture SON...
                }else {
                    [self.meWallUserPictures addObject:[UIImage imageNamed:@"default_profile.jpg"]];
                }

            }
            
            if (objectCountPr == 10){
                
                CheckinAward_CA_PersonalCheckin *personalCheckins = [[CheckinAward_CA_PersonalCheckin alloc] init];
                
                CheckinAward_User *user = [[CheckinAward_User alloc] init];
                user.name = @"Load More...";
                user.ID_ = [NSNumber numberWithInt:-1];
                personalCheckins.CA_CheckedInUser = user;
                [self.meWallArray addObject:personalCheckins];
                [self.meWallTable reloadData];
            }
            
            [HUD hide:YES];
            [_meWallTable reloadData];
        }
        else if ([mine isKindOfClass:[CheckinAward_GetPersonalInfoResponse class]]){
            [HUD show:YES];
            
            id personInfo = [mine GetPersonalInfoResult];
            id currentUser = [personInfo CurrentUser];
            
            
            //ProfilePicture BAŞ...
            [Base64 initialize];
            NSData * data = [Base64 decode:[currentUser CA_personPhotoUrl]];
            if (data != NULL){
                _userPicture.image = [UIImage imageWithData:data];}
            //ProfilePicture SON...
            
            //User Name BAŞ
            _userNameLabel.text = [currentUser name];
            _userCityLabel.text = [currentUser eMail];
            [self.navigationItem setTitle:[currentUser name]];
            
        }
        else if ([mine isKindOfClass:[CheckinAward_AddAsFriendResponse class]]){
        
            NSLog(@"Arkadaş olarak eklendi");
            [_showFriendsButton setTitle:@"Remove from Friends" forState:UIControlStateNormal];
            [self.isFriend setBoolValue:1];
            
            UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Add Friend"
                                                              message:@"Adding Friend is Successful!"
                                                             delegate:nil
                                                    cancelButtonTitle:@"OK"
                                                    otherButtonTitles:nil];
            [message show];
        }
        else if ([mine isKindOfClass:[CheckinAward_DeleteFriendResponse class]]){
            NSLog(@"Arkadaş listesinden çıkarıldı.");
            [_showFriendsButton setTitle:@"Add as Friend" forState:UIControlStateNormal];
            [self.isFriend setBoolValue:0];
            
            UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Remove Friend"
                                                              message:@"Removing Friend is Successful!"
                                                             delegate:nil
                                                    cancelButtonTitle:@"OK"
                                                    otherButtonTitles:nil];
            [message show];
        }
        else {
        
            [HUD hide:YES];
        }

    }
    
}
- (IBAction)showAllFriendsClicked {
    
    tohumPlistControl *control = [[tohumPlistControl alloc] init];
    if (![self.friendID isEqualToNumber:[control getUserIDnumber]]){
    
        if (![self.isFriend boolValue]) {//Arkadaş olarak eklemek...
    
            tohumPlistControl *control = [[tohumPlistControl alloc] init];
            tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
            CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
        
            CheckinAward_AddAsFriend *addFriend = [[CheckinAward_AddAsFriend alloc] init];
            addFriend.ownerUserID = [control getUserIDnumber];
            addFriend.friendID = self.friendID;
        
            [binding AddAsFriendAsyncUsingParameters:addFriend delegate:self];
        }
        else {
            tohumPlistControl *control = [[tohumPlistControl alloc] init];
            tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
            CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
            
            CheckinAward_DeleteFriend *deleteFriend = [[CheckinAward_DeleteFriend alloc] init];
            deleteFriend.ownerUserID = [control getUserIDnumber];
            deleteFriend.friendID = self.friendID;
            
            [binding DeleteFriendAsyncUsingParameters:deleteFriend delegate:self];
        }
    } else {
        
        tohumFriendsViewController *me = [[tohumFriendsViewController alloc] initWithNibName:@"tohumFriendsViewController" bundle:nil];
        tohumAppDelegate *objAppDelegate=(tohumAppDelegate *)[[UIApplication sharedApplication] delegate];
        [objAppDelegate.navController pushViewController:me animated:YES];
    }
}

- (IBAction)editProfileClicked {
    
    tohumMeViewController *me = [[tohumMeViewController alloc] initWithNibName:@"tohumMeViewController" bundle:nil];
    tohumAppDelegate *objAppDelegate=(tohumAppDelegate *)[[UIApplication sharedApplication] delegate];
    [objAppDelegate.navController pushViewController:me animated:YES];
    
}
- (void)goRefresh
{

    [HUD show:YES];
    [self getPersonalInfo:self.friendID];
    [self connectCheckinService:self.friendID];
}
@end
