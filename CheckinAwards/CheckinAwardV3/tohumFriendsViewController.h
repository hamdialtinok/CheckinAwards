//
//  tohumFriendsViewController.h
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

@interface tohumFriendsViewController : UIViewController <UITableViewDataSource,UITableViewDelegate,CheckinAwardSoap12BindingResponseDelegate,MBProgressHUDDelegate>{

    NSMutableArray *wallArray;
    MBProgressHUD *HUD;
    NSInteger pagingTokenFr;
    NSInteger objectCountFr;
}

@property (retain, nonatomic) IBOutlet UITableView *wallTABLE;
@property (retain, nonatomic) NSMutableArray *wallArray;
@end
