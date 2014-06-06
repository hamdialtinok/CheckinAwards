//
//  tohumViewController.h
//  CheckinAwardV3
//
//  Created by Hamdi ALTINOK on 03.01.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "tohumSingupViewController.h"
#import "tohumAppDelegate.h"
#import "tohumLoginViewController.h"
#import <FacebookSDK/FacebookSDK.h>
#import "CheckinAward.h"
#import "KeychainItemWrapper.h"
#import "Reachability.h"
#import "tohumMeViewController.h"
#import "tohumProfileViewController.h"
#import "tohumFriendsADDViewController.h"
#import "tohumFriendsViewController.h"
#import "MBProgressHUD.h"

@interface tohumViewController : UIViewController<FBLoginViewDelegate,CheckinAwardSoap12BindingResponseDelegate>
{
    MBProgressHUD *HUD;
}
- (IBAction)btnSignupClicked;
- (IBAction)btnLoginClicked;
@property (strong, nonatomic) id<FBGraphUser> loggedInUser;
@property (retain, nonatomic) IBOutlet UIView *facebookView;
@property (nonatomic,retain) IBOutlet UIActivityIndicatorView * activityView;
@property (nonatomic ,strong) Reachability* internetReachable;
@property (nonatomic ,strong) Reachability* hostReachable;
@property (nonatomic) Boolean internetActive;
- (IBAction)deneme;

-(void) checkNetworkStatus:(NSNotification *)notice;

@end
