//
//  tohumSingupViewController.h
//  CheckinAwardV3
//
//  Created by Hamdi ALTINOK on 03.01.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CheckinAward.h"
#import "tohumAppDelegate.h"
#import "tohumHomeViewController.h"
#import "tohumPlistControl.h"

@interface tohumSingupViewController : UIViewController <CheckinAwardSoap12BindingResponseDelegate>
@property (retain, nonatomic) IBOutlet UITextField *txtName;
@property (retain, nonatomic) IBOutlet UITextField *txtSurname;
@property (retain, nonatomic) IBOutlet UITextField *txtEmail;
@property (retain, nonatomic) IBOutlet UITextField *txtPassword;
@property (retain, nonatomic) IBOutlet UINavigationBar *navibarSingup;
@property (retain, nonatomic) IBOutlet UILabel *girisGecersizLABEL;
- (IBAction)keyboardRes;

- (IBAction)btnSingupClicked;
@end
