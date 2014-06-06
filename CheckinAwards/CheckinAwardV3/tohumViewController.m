//
//  tohumViewController.m
//  CheckinAwardV3
//
//  Created by Hamdi ALTINOK on 03.01.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumViewController.h"

@interface tohumViewController ()

@end

@implementation tohumViewController
@synthesize loggedInUser = _loggedInUser;
@synthesize internetReachable, hostReachable;
- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // check for internet connection
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(checkNetworkStatus:) name:kReachabilityChangedNotification object:nil];
    
    internetReachable = [[Reachability reachabilityForInternetConnection] retain];
    [internetReachable startNotifier];
    
    // check if a pathway to a random host exists
    hostReachable = [[Reachability reachabilityWithHostName: @"www.apple.com"] retain];
    [hostReachable startNotifier];
    
	// Do any additional setup after loading the view, typically from a nib.
    [self.navigationController setNavigationBarHidden:NO animated:YES];
    self.navigationItem.title = @"Checkin Award";
    
    self.view.backgroundColor = [[UIColor alloc] initWithPatternImage:[UIImage imageNamed:@"Adsız1.png"]];
    FBLoginView *loginView = [[FBLoginView alloc] init];
    loginView.frame = CGRectOffset(loginView.frame, 0, 5);
    loginView.delegate = self;
    [_facebookView addSubview:loginView];
    [loginView sizeToFit];
    
}

- (IBAction)deneme {
    
    /*tohumMeViewController *me = [[tohumMeViewController alloc] initWithNibName:@"tohumMeViewController" bundle:nil];
    tohumAppDelegate *objAppDelegate=(tohumAppDelegate *)[[UIApplication sharedApplication] delegate];
    [objAppDelegate.navController pushViewController:me animated:YES];*/
    
    /*tohumProfileViewController *me = [[tohumProfileViewController alloc] initWithNibName:@"tohumProfileViewController" bundle:nil];
    tohumAppDelegate *objAppDelegate=(tohumAppDelegate *)[[UIApplication sharedApplication] delegate];
    [objAppDelegate.navController pushViewController:me animated:YES];*/
    
    /*tohumFriendsADDViewController *me = [[tohumFriendsADDViewController alloc] initWithNibName:@"tohumFriendsADDViewController" bundle:nil];
    [me setTitle:@"Search"];
    tohumAppDelegate *objAppDelegate=(tohumAppDelegate *)[[UIApplication sharedApplication] delegate];
    [objAppDelegate.navController pushViewController:me animated:YES];*/
    
    tohumFriendsViewController *me = [[tohumFriendsViewController alloc] initWithNibName:@"tohumFriendsViewController" bundle:nil];
    tohumAppDelegate *objAppDelegate=(tohumAppDelegate *)[[UIApplication sharedApplication] delegate];
    [objAppDelegate.navController pushViewController:me animated:YES];
    
}

-(void) checkNetworkStatus:(NSNotification *)notice
{
    // called after network status changes
    NetworkStatus internetStatus = [internetReachable currentReachabilityStatus];
    switch (internetStatus)
    {
        case NotReachable:
        {
            NSLog(@"The internet is down.");
            self.internetActive = NO;
            
            break;
        }
        case ReachableViaWiFi:
        {
            NSLog(@"The internet is working via WIFI.");
            self.internetActive = YES;
            
            break;
        }
        case ReachableViaWWAN:
        {
            NSLog(@"The internet is working via WWAN.");
            self.internetActive = YES;
            
            break;
        }
    }
    
    if (self.internetActive == NO){
        [self showNetworkMessage];
    }
    
}

- (void) showNetworkMessage{
    UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Network Unavailable"
                                                     message:@"App content may be limited without a network connection!"
                                                    delegate:self
                                           cancelButtonTitle:@"OK"
                                           otherButtonTitles:nil] autorelease];
    [alert show];
}

- (void) loginViewShowingLoggedInUser:(FBLoginView *)loginView{
    
    
        if (FBSession.activeSession.isOpen) {
            [[FBRequest requestForMe] startWithCompletionHandler:^(FBRequestConnection *connection, NSDictionary<FBGraphUser> *user, NSError *error) {
                if (!error) {
                
                    NSLog(@"username : %@",user.name);
                    NSLog(@"email : %@",user.username);
                
                    
                    //HUD BAŞ...
                    HUD = [[MBProgressHUD alloc] initWithView:self.view];
                    [self.view addSubview:HUD];
                    
                    HUD.dimBackground = YES;
                    [HUD show:YES];
                    //HUD SON...
                
                    KeychainItemWrapper *keychain =
                    [[KeychainItemWrapper alloc] initWithIdentifier:@"TestAppLoginData" accessGroup:nil];
                
                    
                    [keychain setObject:user.username forKey:(id)kSecAttrAccount];
                    [keychain setObject:@"facebook" forKey:(id)kSecValueData];
                
                    tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
                    CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
                
                    CheckinAward_Login *userLogin = [[CheckinAward_Login alloc] init];
                    userLogin.userName = user.username;
                    userLogin.password = @"facebook";
                
                    [binding LoginAsyncUsingParameters:userLogin delegate:self];
                }
            }];
        }
}
- (void) operation:(CheckinAwardSoap12BindingOperation *)operation completedWithResponse:(CheckinAwardSoap12BindingResponse *)response{
    
    NSString *username=nil;
    NSNumber *userID=0;
    for (id mine in response.bodyParts){
        if ([mine isKindOfClass:[CheckinAward_LoginResponse class]]){
            username = [[mine LoginResult] userName];
            userID = [[mine LoginResult] ID_];
            NSLog(@"Login> response> username: %@",username);
            NSLog(@"Login> response> username: %@",[[mine LoginResult] ID_]);
            if (username != nil){
                
                NSLog(@"Login> response> başarılı işlem: login");
                
                tohumPlistControl *control = [[tohumPlistControl alloc] init];
                [control setUserID: [userID stringValue]];
                [control setUserNAME:[userID stringValue]];
                NSLog(@"Reading userid from plist: %@",[control getUserID]);
                NSLog(@"Reading username from plist: %@",[control getUserNAME]);
                
                
                [self dismissViewControllerAnimated:YES completion:nil];
                
                /*tohumHomeViewController *signup = [[tohumHomeViewController alloc] initWithNibName:@"tohumHomeViewController" bundle:nil];
                
                [objAppDelegate.navController pushViewController:signup animated:YES];*/
            }
            else {
            
                tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
                CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
                
                
                CheckinAward_User *user = [[CheckinAward_User alloc] init];
                user.name = [_loggedInUser first_name];
                user.surname = [_loggedInUser last_name];
                user.eMail = [_loggedInUser username];
                user.password = @"facebook";
                user.userName = [_loggedInUser username];
                
                
                CheckinAward_SignUp *param = [[CheckinAward_SignUp alloc] init];
                param.insertUser = user;
                [binding SignUpAsyncUsingParameters:param delegate:self];
                [param release];
            }
        }
        else if ([mine isKindOfClass:[CheckinAward_SignUpResponse class]]){
            
            username = [[mine SignUpResult] userName];
            userID = [[mine SignUpResult] ID_];
            NSLog(@"Sign up> response> username: %@",username);
            if (username != nil){
                NSLog(@"Sign up> response> başarılı işlem: singup");
                
                tohumPlistControl *control = [[tohumPlistControl alloc] init];
                [control setUserID: [userID stringValue]];
                [control setUserNAME: username];
                NSLog(@"Reading userid from plist: %@",[control getUserID]);
                NSLog(@"Reading username from plist: %@",[control getUserNAME]);

                
                [self
                 dismissViewControllerAnimated:YES completion:nil];
            }
        }
        else {// Eğer yanlış bilgi girilirse
            
            tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
            CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
            
            
            CheckinAward_User *user = [[CheckinAward_User alloc] init];
            user.name = [_loggedInUser first_name];
            user.surname = [_loggedInUser last_name];
            user.eMail = [_loggedInUser username];
            user.password = @"facebook";
            user.userName = [_loggedInUser username];
            
            
            CheckinAward_SignUp *param = [[CheckinAward_SignUp alloc] init];
            param.insertUser = user;
            [binding SignUpAsyncUsingParameters:param delegate:self];
            [param release];
        }
    }[HUD hide:YES];
    
}
- (void)loginViewFetchedUserInfo:(FBLoginView *)loginView user:(id<FBGraphUser>)user{
    
    self.loggedInUser = user;
}

- (void) loginViewShowingLoggedOutUser:(FBLoginView *)loginView{
    
    self.loggedInUser = nil;
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)btnSignupClicked {
    
    
    if (self.internetActive){
    
        tohumAppDelegate *objAppDelegate=(tohumAppDelegate *)[[UIApplication sharedApplication] delegate];
    
        tohumSingupViewController *signup = [[tohumSingupViewController alloc] initWithNibName:@"tohumSingupViewController" bundle:nil];
    
        [objAppDelegate.navController4 pushViewController:signup animated:YES];
    }
    else{
        [self showNetworkMessage];
    }
}

- (IBAction)btnLoginClicked {
    
    if (self.internetActive){
    
        tohumAppDelegate *objAppDelegate=(tohumAppDelegate *)[[UIApplication sharedApplication] delegate];
    
        tohumLoginViewController *login = [[tohumLoginViewController alloc] initWithNibName:@"tohumLoginViewController" bundle:nil];
    
        [objAppDelegate.navController4 pushViewController:login animated:YES];
        
    }else {
        [self showNetworkMessage];
    }
}
- (void)dealloc {
    [_facebookView release];
    [super dealloc];
}
@end
