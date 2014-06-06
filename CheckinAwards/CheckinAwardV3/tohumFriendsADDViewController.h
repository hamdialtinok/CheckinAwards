//
//  tohumFriendsADDViewController.h
//  checkin awards
//
//  Created by Hamdi ALTINOK on 13.03.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "tohumFriendsCustomCell.h"
#import "CheckinAward.h"
#import "tohumPlistControl.h"
#import "Base64.h"
#import "tohumAppDelegate.h"
#import "tohumProfileViewController.h"
#import "MBProgressHUD.h"


@interface tohumFriendsADDViewController : UIViewController<UITableViewDelegate,UITableViewDataSource,UISearchBarDelegate,CheckinAwardSoap12BindingResponseDelegate,MBProgressHUDDelegate>
{
    NSMutableArray *friendsArray;
    MBProgressHUD *HUD;
    
    NSInteger pagingTokenAdFr;
    NSInteger objectCountAdFr;
    NSString *searchBarText;
}
@property (retain, nonatomic) IBOutlet UISearchBar *searchFriends;
@property (retain, nonatomic) IBOutlet UITableView *friendsTable;
@property (retain, nonatomic) NSMutableArray *friendsArray;
@end
