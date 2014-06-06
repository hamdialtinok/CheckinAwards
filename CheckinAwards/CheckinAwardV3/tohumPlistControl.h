//
//  tohumPlistControl.h
//  CheckinAwardV3
//
//  Created by Hamdi ALTINOK on 10.01.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface tohumPlistControl : NSObject

@property (nonatomic, strong) NSString *userNAME;
@property (nonatomic, strong) NSString *userID;

- (NSString *) getUserID;
-(void) setUserID:(NSString *)newuserID;
- (NSString *) getUserNAME;
-(void) setUserNAME:(NSString *)newuserNAME;
- (NSNumber *) getUserIDnumber;
@end
