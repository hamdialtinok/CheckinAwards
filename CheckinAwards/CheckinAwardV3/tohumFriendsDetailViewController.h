//
//  tohumFriendsDetailViewController.h
//  checkin awards
//
//  Created by Hamdi ALTINOK on 13.03.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "tohumFriendsCustomCell.h"

@interface tohumFriendsDetailViewController : UIViewController <UITableViewDelegate,UITableViewDataSource>{

    NSMutableArray *commentArray;
}

@property (retain, nonatomic) IBOutlet UITextField *commentTextView;
@property (retain, nonatomic) NSMutableArray *commentArray;
@property (retain, nonatomic) IBOutlet UITableView *commentTABLE;
@property (retain, nonatomic) IBOutlet UIImageView *userPicture;
@property (retain, nonatomic) IBOutlet UILabel *awardLabel;
- (IBAction)btnCommentSendClicked;

@end
