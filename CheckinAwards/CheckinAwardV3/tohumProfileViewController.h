//
//  tohumProfileViewController.h
//  checkin awards
//
//  Created by Hamdi ALTINOK on 13.03.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "tohumFriendsCustomCell.h"
#import "tohumAppDelegate.h"
#import "CheckinAward.h"
#import "tohumPlistControl.h"
#import "Base64.h"
#import "MBProgressHUD.h"
#import "tohumFriendsViewController.h"

@interface tohumProfileViewController : UIViewController<UITableViewDataSource,UITableViewDelegate,CheckinAwardSoap12BindingResponseDelegate,MBProgressHUDDelegate>{

    NSMutableArray *meWallArray;
    NSMutableArray *meWallDictionary;
    NSMutableArray *meWallUserPictures;
    NSMutableArray *meWallAwardPictures;
    USBoolean *isFriend;
    NSNumber *friendID;
    MBProgressHUD *HUD;
    
    NSInteger pagingTokenPr;
    NSInteger objectCountPr;
}

@property (retain, nonatomic) IBOutlet UILabel *userNameLabel;
@property (retain, nonatomic) IBOutlet UILabel *userCityLabel;
@property (retain, nonatomic) IBOutlet UIImageView *userPicture;
@property (retain, nonatomic) IBOutlet UITableView *meWallTable;
@property (retain, nonatomic) NSMutableArray *meWallArray;
@property (retain, nonatomic) NSMutableArray *meWallDictionary;
@property (retain, nonatomic) NSMutableArray *meWallUserPictures;
@property (retain, nonatomic) NSMutableArray *meWallAwardPictures;
@property (retain, nonatomic) USBoolean *isFriend;
@property (retain, nonatomic) NSNumber *friendID;
@property (retain, nonatomic) IBOutlet UIButton *editProfileButton;
@property (retain, nonatomic) IBOutlet UIButton *showFriendsButton;
@property (retain, nonatomic) IBOutlet UILabel *editProfileLAbel;

- (IBAction)showAllFriendsClicked;
- (IBAction)editProfileClicked;

@end
