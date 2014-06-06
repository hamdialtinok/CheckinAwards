//
//  tohumLoginViewController.h
//  CheckinAwardV3
//
//  Created by Hamdi ALTINOK on 10.01.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CheckinAward.h"
#import "tohumAppDelegate.h"
#import "tohumPlistControl.h"
#import "KeychainItemWrapper.h"

@interface tohumLoginViewController : UIViewController <CheckinAwardSoap12BindingResponseDelegate>
@property (retain, nonatomic) IBOutlet UITextField *emailTEXTFIELD;
@property (retain, nonatomic) IBOutlet UITextField *passwordTEXTFIELD;
- (IBAction)loginBUTTON_CLICKED;
- (IBAction)hideBUTTON;
@property (retain, nonatomic) IBOutlet UILabel *girisBasarisizLABEL;
@property (retain, nonatomic) IBOutlet UILabel *recoveryLabel;

@end
