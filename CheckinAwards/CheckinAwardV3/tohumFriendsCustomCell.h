//
//  tohumFriendsCustomCell.h
//  checkin awards
//
//  Created by Hamdi ALTINOK on 13.03.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface tohumFriendsCustomCell : UITableViewCell

@property (nonatomic, strong) IBOutlet UIImageView *userPicture;
@property (nonatomic, strong) IBOutlet UIImageView *AwardsPicture;
@property (nonatomic, strong) IBOutlet UILabel *userName;
@property (nonatomic, strong) IBOutlet UILabel *AwardsDetail;
@property (nonatomic, strong) IBOutlet UILabel *dateLabel;
@property (nonatomic, strong) IBOutlet UILabel *CommentsLabel;

@end
