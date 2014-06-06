//
//  tohumFriendsCustomCell.m
//  checkin awards
//
//  Created by Hamdi ALTINOK on 13.03.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumFriendsCustomCell.h"

@implementation tohumFriendsCustomCell

@synthesize userPicture = _userPicture;
@synthesize AwardsPicture = _AwardsPicture;
@synthesize userName = _userName;
@synthesize AwardsDetail = _AwardsDetail;
@synthesize dateLabel = _dateLabel;
@synthesize CommentsLabel = _CommentsLabel;

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
