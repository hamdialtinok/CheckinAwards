//
//  tohumMeViewController.m
//  checkin awards
//
//  Created by Hamdi ALTINOK on 19.02.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumMeViewController.h"

@interface tohumMeViewController ()

@end

@implementation tohumMeViewController

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
    _imageProfil.userInteractionEnabled = YES;
    [self connectCheckinService];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string {
    
    if ([textField.placeholder isEqual:@"dd"]){
    
        NSLog(@"%@",string);
        NSUInteger newLength = [textField.text length] + [string length] - range.length;
        return (newLength > 2) ? NO : YES;
    }
    else if ([textField.placeholder isEqual:@"mm"]){
        NSLog(@"%@",string);
        NSUInteger newLength = [textField.text length] + [string length] - range.length;
        return (newLength > 2) ? NO : YES;
    }
    else {
        NSLog(@"%@",string);
        NSUInteger newLength = [textField.text length] + [string length] - range.length;
        return (newLength > 4) ? NO : YES;
    }
    
}

- (void)dealloc {
    [_imageProfil release];
    [_txtSettingNAME release];
    [_txtSettingSURNAME release];
    [_txtSettingEMAIL release];
    [_btnSettingFEMALE release];
    [_btnSettingMALE release];
    [_btnSaveChanges release];
    [super dealloc];
}
- (IBAction)hideBUTTON {
    [_txtSettingNAME resignFirstResponder];
    [_txtSettingSURNAME resignFirstResponder];
    [_txtSettingEMAIL resignFirstResponder];
}

- (IBAction)btnSaveChangesClicked:(id)sender {
    
    tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
    CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
    
    KeychainItemWrapper *keychain =
    [[KeychainItemWrapper alloc] initWithIdentifier:@"TestAppLoginData" accessGroup:nil];
    NSLog(@"User Name: %@",[keychain objectForKey:(id)kSecAttrAccount]);
    
    tohumPlistControl *control = [[tohumPlistControl alloc] init];
    NSNumberFormatter * f = [[NSNumberFormatter alloc] init];
    [f setNumberStyle:NSNumberFormatterDecimalStyle];
    
    //image BAŞ
    NSData* data = UIImageJPEGRepresentation(_imageProfil.image, 1.0f);
    [Base64 initialize];
    NSString *strEncoded = [Base64 encode:data];
    //İmage SON
    
    
    CheckinAward_CA_AddPersonalInfo *user = [[CheckinAward_CA_AddPersonalInfo alloc] init];
    user.userID = [f numberFromString:[control getUserNAME]];
    user.name = _txtSettingNAME.text;
    user.surname = _txtSettingSURNAME.text;
    user.email = _txtSettingEMAIL.text;
    user.profilePhoto = strEncoded;
    
    
    [binding CA_AddPersonalInfoAsyncUsingParameters:user delegate:self];
}
- (void) operation:(CheckinAwardSoap12BindingOperation *)operation completedWithResponse:(CheckinAwardSoap12BindingResponse *)response{
    NSLog(@"%@",response);
    
    for (id mine in response.bodyParts){
        if ([mine isKindOfClass:[CheckinAward_GetPersonalInfoResponse class]]){
            
            id personInfo = [mine GetPersonalInfoResult];
            id currentUser = [personInfo CurrentUser];
            
            //ProfilePicture BAŞ...
            [Base64 initialize];
            NSData * data = [Base64 decode:[currentUser CA_personPhotoUrl]];
            if (data != NULL){
                _imageProfil.image = [UIImage imageWithData:data];}
            //ProfilePicture SON...
            
            //User Name BAŞ
            _txtSettingNAME.text = [currentUser name];
            _txtSettingSURNAME.text = [currentUser surname];
            _txtSettingEMAIL.text = [currentUser eMail];
            
        }
    }
    
}
-(void)imagePickerController:(UIImagePickerController *)picker
      didFinishPickingImage : (UIImage *)image
                 editingInfo:(NSDictionary *)editingInfo
{
    _imageProfil.image = image;
    [picker dismissModalViewControllerAnimated:YES];
}
-(void)imagePickerControllerDidCancel:(UIImagePickerController *)  picker
{
    [picker dismissViewControllerAnimated:YES completion:nil];
}
-(void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    NSLog(@"sdfsdfg");
    //your UIImageView has been touched :)
    
    //event -> "A UIEvent object representing the event to which the touches belong."
    
    //touches -> "A set of UITouch instances in the event represented by event that    represent the touches in the UITouchPhaseEnded phase."
    UIImagePickerController *picker = [[UIImagePickerController alloc] init];
    picker.delegate = self;
    picker.allowsEditing = YES;
    //picker.sourceType = (sender == takePictureButton) ?    UIImagePickerControllerSourceTypeCamera :
    //UIImagePickerControllerSourceTypeSavedPhotosAlbum;
    picker.sourceType =  UIImagePickerControllerSourceTypePhotoLibrary;
    [self presentViewController: picker animated:YES completion:nil];
    [picker release];
    
}

- (void) connectCheckinService {
    
    
    tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
    CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
    
    tohumPlistControl *control = [[tohumPlistControl alloc] init];
    NSNumberFormatter * f = [[NSNumberFormatter alloc] init];
    [f setNumberStyle:NSNumberFormatterDecimalStyle];
    
    CheckinAward_GetPersonalInfo *user = [[CheckinAward_GetPersonalInfo alloc] init];
    
    user.userID =[f numberFromString:[control getUserNAME]];
    
    [f release];
    
    [binding GetPersonalInfoAsyncUsingParameters:user delegate:self];
    
}


@end
