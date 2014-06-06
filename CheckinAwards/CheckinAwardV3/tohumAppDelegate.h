//
//  tohumAppDelegate.h
//  CheckinAwardV3
//
//  Created by Hamdi ALTINOK on 03.01.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "tohumViewController.h"
#import "Facebook.h"
#import "tohumProfileViewController.h"
#import "tohumHomeViewController.h"
#import "tohumFriendsADDViewController.h"
#import "tohumMeWallViewController.h"
#import "tohumPlistControl.h"

@class tohumViewController;

@interface tohumAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) UINavigationController *navController;
@property (strong, nonatomic) UINavigationController *navController2;
@property (strong, nonatomic) UINavigationController *navController3;
@property (strong, nonatomic) UITabBarController *tabController;
@property (strong, nonatomic) UINavigationController *navController4;

- (CheckinAwardSoap12Binding *) Soap12Binding;

@end
