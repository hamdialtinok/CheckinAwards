//
//  tohumShowFriendsViewController.h
//  checkin awards
//
//  Created by Hamdi ALTINOK on 13.03.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "tohumFriendsCustomCell.h"

@interface tohumShowFriendsViewController : UIViewController<UITableViewDataSource,UITableViewDelegate>{

    NSMutableArray *friendsArray;
}
@property (retain, nonatomic) IBOutlet UITableView *friendsTable;
@property (retain, nonatomic) NSMutableArray *friendsArray;
@end
