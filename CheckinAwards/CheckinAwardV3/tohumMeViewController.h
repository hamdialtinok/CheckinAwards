//
//  tohumMeViewController.h
//  checkin awards
//
//  Created by Hamdi ALTINOK on 19.02.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CheckinAward.h"
#import "tohumAppDelegate.h"

@interface tohumMeViewController : UIViewController<UITextFieldDelegate,CheckinAwardSoap12BindingResponseDelegate,UIImagePickerControllerDelegate,UINavigationControllerDelegate>

@property (retain, nonatomic) IBOutlet UIImageView *imageProfil;
@property (retain, nonatomic) IBOutlet UITextField *txtSettingNAME;
@property (retain, nonatomic) IBOutlet UITextField *txtSettingSURNAME;
@property (retain, nonatomic) IBOutlet UITextField *txtSettingEMAIL;
@property (retain, nonatomic) IBOutlet UIButton *btnSettingFEMALE;
@property (retain, nonatomic) IBOutlet UIButton *btnSettingMALE;
@property (retain, nonatomic) IBOutlet UIButton *btnSaveChanges;
- (IBAction)hideBUTTON;
- (IBAction)btnSaveChangesClicked:(id)sender;
@end
