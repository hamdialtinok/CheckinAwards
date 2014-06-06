//
//  tohumMeWallViewController.h
//  checkin awards
//
//  Created by Hamdi ALTINOK on 19.03.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "tohumFriendsCustomCell.h"
#import "tohumAppDelegate.h"
#import "CheckinAward.h"
#import "tohumPlistControl.h"
#import "Base64.h"
#import "MBProgressHUD.h"

@interface tohumMeWallViewController : UIViewController <UITableViewDataSource,UITableViewDelegate,CheckinAwardSoap12BindingResponseDelegate,MBProgressHUDDelegate>{
    
    NSMutableArray *wallArray;
    
    NSMutableArray *WallUserPictures;
    NSMutableArray *WallAwardPictures;
    MBProgressHUD *HUD;
}

@property (retain, nonatomic) IBOutlet UITableView *wallTABLE;
@property (retain, nonatomic) NSMutableArray *wallArray;

@property (retain, nonatomic) NSMutableArray *WallUserPictures;
@property (retain, nonatomic) NSMutableArray *WallAwardPictures;
 
@end
