//
//  tohumLoginViewController.m
//  CheckinAwardV3
//
//  Created by Hamdi ALTINOK on 10.01.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumLoginViewController.h"

@interface tohumLoginViewController ()

@end

@implementation tohumLoginViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    [self.navigationController setNavigationBarHidden:NO animated:YES];
    [self.navigationItem setTitle:@"Log In"];
    [self.navigationController.navigationBar setBackgroundColor:[UIColor colorWithRed:0 green:192 blue:227 alpha:1]];
    
    self.view.backgroundColor = [[UIColor alloc] initWithPatternImage:[UIImage imageNamed:@"leather_iphone_wallpaper-t2.jpg"]];
    
    _recoveryLabel.userInteractionEnabled = YES;
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTap:)];
    [_recoveryLabel addGestureRecognizer:tap];
    [tap release];
    
    [_girisBasarisizLABEL setHidden:true];
    _passwordTEXTFIELD.secureTextEntry = YES;
    _passwordTEXTFIELD.autocorrectionType = UITextAutocorrectionTypeNo;
    [_passwordTEXTFIELD setClearButtonMode:UITextFieldViewModeWhileEditing];
    [_emailTEXTFIELD setClearButtonMode:UITextFieldViewModeWhileEditing];
    
    [self loginWithKeyChain];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {
    [_emailTEXTFIELD release];
    [_passwordTEXTFIELD release];
    [_girisBasarisizLABEL release];
    [_recoveryLabel release];
    [super dealloc];
}

//Email validation
- (BOOL) validateEmail: (NSString *) candidate {
    NSString *emailRegex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}";
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];
    //    return 0;
    return [emailTest evaluateWithObject:candidate];
}

//Password validation
-(BOOL) isPasswordValid:(NSString *)pwd {
    if ( [pwd length]<6 || [pwd length]>32 ) return NO;  // too long or too short
    NSRange rang;
    rang = [pwd rangeOfCharacterFromSet:[NSCharacterSet letterCharacterSet]];
    if ( !rang.length ) return NO;  // no letter
    return YES;
}

- (void)handleTap:(UITapGestureRecognizer *)recognizer  {
    UILabel *imageView = (UILabel *)recognizer.view;
    [imageView setTextColor:[UIColor whiteColor]];
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"http://checkinawards.com?recover_password=true"]];
}

- (void) loginWithKeyChain {

    KeychainItemWrapper *keychain =
    [[KeychainItemWrapper alloc] initWithIdentifier:@"TestAppLoginData" accessGroup:nil];
    
    if ([[keychain objectForKey:(id)kSecAttrAccount] length] != 0 && [[keychain objectForKey:(id)kSecValueData] length] != 0){
        
        [_emailTEXTFIELD setText:[keychain objectForKey:(id)kSecAttrAccount]];
        NSLog(@"username: %@", [_emailTEXTFIELD text]);
        [_passwordTEXTFIELD setText:[keychain objectForKey:(id)kSecValueData]];
        NSLog(@"password: %@", [_passwordTEXTFIELD text]);
        
    }
}

- (IBAction)loginBUTTON_CLICKED {

    [UIApplication sharedApplication].networkActivityIndicatorVisible = YES;
    
    KeychainItemWrapper *keychain =
    [[KeychainItemWrapper alloc] initWithIdentifier:@"TestAppLoginData" accessGroup:nil];
    
    if ([_emailTEXTFIELD.text length]!=0 && [_passwordTEXTFIELD.text length]!=0){
        
        if([self validateEmail:[_emailTEXTFIELD text]] ==1)
        {
            if ([self isPasswordValid:[_passwordTEXTFIELD text]]){
            
                [keychain setObject:[_emailTEXTFIELD text] forKey:(id)kSecAttrAccount];
                [keychain setObject:[_passwordTEXTFIELD text] forKey:(id)kSecValueData];
                
                tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
                CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
            
                CheckinAward_Login *user = [[CheckinAward_Login alloc] init];
                user.userName = _emailTEXTFIELD.text;
                user.password = _passwordTEXTFIELD.text;
            
                [binding LoginAsyncUsingParameters:user delegate:self];
            }
            else {
                [_girisBasarisizLABEL setHidden:FALSE];
                _girisBasarisizLABEL.text = @"Password must be at least 6 characters and contain at least a letter";
                [_passwordTEXTFIELD setText:@""];
            }
            
        }
        else{
            [_girisBasarisizLABEL setHidden:FALSE];
            _girisBasarisizLABEL.text = @"Invalid email";
            [_passwordTEXTFIELD setText:@""];
        }
    
        
    }else {
    
        [_girisBasarisizLABEL setHidden:FALSE];
        _girisBasarisizLABEL.text = @"Invalid username or password!";
        [_passwordTEXTFIELD setText:@""];
    }
    
    
}

- (IBAction)hideBUTTON {
    [_emailTEXTFIELD resignFirstResponder];
    [_passwordTEXTFIELD resignFirstResponder];
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
            }
        }
        else {// Eğer yanlış bilgi girilirse
        
            _girisBasarisizLABEL.text = @"Invalid username or password!";
            [_girisBasarisizLABEL setHidden:FALSE];
            [_passwordTEXTFIELD setText:@""];
        }
    }
    [UIApplication sharedApplication].networkActivityIndicatorVisible = NO;
}
@end
