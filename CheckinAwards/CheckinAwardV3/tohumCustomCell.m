//
//  tohumCustomCell.m
//  CheckinAwardV3
//
//  Created by Hamdi ALTINOK on 18.01.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumCustomCell.h"

@implementation tohumCustomCell
@synthesize markaIMAGE=_markaIMAGE;
@synthesize markaLABEL1=_markaLABEL1;
@synthesize awardIMAGE=_awardIMAGE;
@synthesize markaNAME=_markaNAME;

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
