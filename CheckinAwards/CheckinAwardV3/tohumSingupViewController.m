//
//  tohumSingupViewController.m
//  CheckinAwardV3
//
//  Created by Hamdi ALTINOK on 03.01.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumSingupViewController.h"

@interface tohumSingupViewController ()

@end

@implementation tohumSingupViewController
@synthesize txtName,txtEmail,txtPassword,txtSurname;

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
    [self.navigationItem setTitle:@"Register"];
    txtPassword.secureTextEntry = YES;
    [_girisGecersizLABEL setHidden:YES];
    txtPassword.autocorrectionType = UITextAutocorrectionTypeNo;
    [txtPassword setClearButtonMode:UITextFieldViewModeWhileEditing];
    [txtName setClearButtonMode:UITextFieldViewModeWhileEditing];
    [txtEmail setClearButtonMode:UITextFieldViewModeWhileEditing];
    [txtSurname setClearButtonMode:UITextFieldViewModeWhileEditing];
    
    self.view.backgroundColor = [[UIColor alloc] initWithPatternImage:[UIImage imageNamed:@"leather_iphone_wallpaper-t2.jpg"]];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)keyboardRes {
    [txtName resignFirstResponder];
    [txtSurname resignFirstResponder];
    [txtEmail resignFirstResponder];
    [txtPassword resignFirstResponder];
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

- (IBAction)btnSingupClicked {
    
    [UIApplication sharedApplication].networkActivityIndicatorVisible = YES;
    
    [txtName resignFirstResponder];
    
    if ([txtEmail.text length]!=0 && [txtName.text length]!=0 && [txtPassword.text length]!=0 && [txtSurname.text length]!=0){

        if([self validateEmail:[txtEmail text]] ==1)
        {
            
            if ([self isPasswordValid:[txtPassword text]]){
        
                tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
                CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
    
    
                CheckinAward_User *user = [[CheckinAward_User alloc] init];
                user.name = txtName.text;
                user.surname = txtSurname.text;
                user.eMail = txtEmail.text;
                user.password = txtPassword.text;
                user.userName = txtEmail.text;
        
    
                CheckinAward_SignUp *param = [[CheckinAward_SignUp alloc] init];
                param.insertUser = user;
                [binding SignUpAsyncUsingParameters:param delegate:self];
                [param release];
            }
            else {
                [_girisGecersizLABEL setHidden:FALSE];
                _girisGecersizLABEL.text = @"Password must be at least 6 characters and contain at least a letter";
                [txtPassword setText:@""];
            }
        }
        else{
            [_girisGecersizLABEL setHidden:FALSE];
            _girisGecersizLABEL.text = @"Invalid email!";
            [txtPassword setText:@""];
        }
    }
    else {
        [_girisGecersizLABEL setHidden:FALSE];
        _girisGecersizLABEL.text = @"Invalid entry!";
    }
    
}

- (void) operation:(CheckinAwardSoap12BindingOperation *)operation completedWithResponse:(CheckinAwardSoap12BindingResponse *)response{

    NSString *username=nil;
    NSNumber *userID = 0;
    for (id mine in response.bodyParts){
        if ([mine isKindOfClass:[CheckinAward_SignUpResponse class]]){
        
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
                
                [self dismissViewControllerAnimated:YES completion:nil];
            }
        }else {
        
            [_girisGecersizLABEL setHidden:NO];
            _girisGecersizLABEL.text = @"Invalid entry!";
            txtPassword.text = @"";
        }
    }
    
    [UIApplication sharedApplication].networkActivityIndicatorVisible = NO;
    
}
- (void)dealloc {
    [txtName release];
    [txtSurname release];
    [txtEmail release];
    [txtPassword release];
    [_navibarSingup release];
    [_girisGecersizLABEL release];
    [super dealloc];
}
@end
