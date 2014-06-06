//
//  tohumAppDelegate.m
//  CheckinAwardV3
//
//  Created by Hamdi ALTINOK on 03.01.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumAppDelegate.h"

#import "tohumViewController.h"

@implementation tohumAppDelegate

- (void)dealloc
{
    [super dealloc];
}
- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation {
    // attempt to extract a token from the url
    return [FBSession.activeSession handleOpenURL:url];
}
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    // Override point for customization after application launch.
    
    tohumViewController *viewController = [[tohumViewController alloc] initWithNibName:@"tohumViewController" bundle:nil];
    /*tohumProfileViewController *viewController2 = [[tohumProfileViewController alloc] initWithNibName:@"tohumProfileViewController" bundle:nil];
    tohumHomeViewController *viewController3 = [[tohumHomeViewController alloc] initWithNibName:@"tohumHomeViewController" bundle:nil];
    self.navController = [[UINavigationController alloc] initWithRootViewController:viewController];
    UINavigationBar *navBar = [[self navController] navigationBar];
    [navBar setBarStyle:UIBarStyleBlackOpaque];
    
    self.tabController = [[UITabBarController alloc] init];
    self.tabController.viewControllers = [NSArray arrayWithObjects:viewController3,viewController2, nil];*/
    [self setTabbarItems];
    
    //self.window.rootViewController = self.tabController;

    [self.window addSubview:self.tabController.view];
    self.navController4 = [[UINavigationController alloc] initWithRootViewController:viewController];
    UINavigationBar *navBar = [[self navController4] navigationBar];
    [navBar setBarStyle:UIBarStyleBlackOpaque];
    [self.tabController presentViewController:self.navController4 animated:NO completion:nil];
    
    [self.window makeKeyAndVisible];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    [FBSession.activeSession handleDidBecomeActive];
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    [FBSession.activeSession close];
}

- (CheckinAwardSoap12Binding *) Soap12Binding{

    CheckinAwardSoap12Binding *binding = [[CheckinAward CheckinAwardSoap12Binding] initWithAddress:@"http://checkinaward.infratek.net/CheckinAward.asmx"];
    binding.logXMLInOut = YES;
    
    return binding;
}

- (void) setTabbarItems{

    
    tohumPlistControl *control = [[tohumPlistControl alloc] init];
    
    tohumHomeViewController *homeView = [[tohumHomeViewController alloc] initWithNibName:@"tohumHomeViewController" bundle:nil];
    
    tohumProfileViewController *profileView = [[tohumProfileViewController alloc] initWithNibName:@"tohumProfileViewController" bundle:nil];
    profileView.friendID = [control getUserIDnumber];
    
    tohumFriendsADDViewController *addFriendsView = [[tohumFriendsADDViewController alloc] initWithNibName:@"tohumFriendsADDViewController" bundle:nil];
    
    tohumMeWallViewController *meWallView = [[tohumMeWallViewController alloc] initWithNibName:@"tohumMeWallViewController" bundle:nil];
    
    
    self.navController = [[UINavigationController alloc] initWithRootViewController:profileView];
    UINavigationBar *navBar = [[self navController] navigationBar];
    [navBar setBarStyle:UIBarStyleBlackOpaque];
    
    self.navController2 = [[UINavigationController alloc] initWithRootViewController:addFriendsView];
    UINavigationBar *navBar2 = [[self navController2] navigationBar];
    [navBar2 setBarStyle:UIBarStyleBlackOpaque];
    
    self.navController3 = [[UINavigationController alloc] initWithRootViewController:homeView];
    UINavigationBar *navBar3 = [[self navController3] navigationBar];
    [navBar3 setBarStyle:UIBarStyleBlackOpaque];
    
    self.tabController = [[UITabBarController alloc] init];
    self.tabController.viewControllers = [NSArray arrayWithObjects:self.navController3,meWallView,self.navController,self.navController2, nil];
}

@end
