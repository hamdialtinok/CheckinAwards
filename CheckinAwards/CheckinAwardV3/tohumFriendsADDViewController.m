//
//  tohumFriendsADDViewController.m
//  checkin awards
//
//  Created by Hamdi ALTINOK on 13.03.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumFriendsADDViewController.h"

@interface tohumFriendsADDViewController ()

@end

@implementation tohumFriendsADDViewController
@synthesize friendsArray;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
        self.tabBarItem.image = [UIImage imageNamed:@"Search kopya"];
        self.tabBarItem.title = @"Search";
        [self.navigationItem setTitle:@"Search People"];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.friendsArray = [[NSMutableArray alloc] init];
    HUD = [[MBProgressHUD alloc] initWithView:self.view];
	[self.view addSubview:HUD];
	
	HUD.dimBackground = YES;
    
    pagingTokenAdFr = 1;
    objectCountAdFr = 0;
}
- (void)viewDidAppear:(BOOL)animated {
    [self.searchFriends becomeFirstResponder];
    [super viewDidAppear:animated];
}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {
    [_searchFriends release];
    [_friendsTable release];
    [super dealloc];
}
//Table view row selection
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    //table da seçim yapılıp yapıladığını kontrol eder
    NSLog(@"Table view tıklandı");
    
    CheckinAward_User *user = [self.friendsArray objectAtIndex:[indexPath row]];
    
    if ([user.ID_ isEqualToNumber:[NSNumber numberWithInt:-1]]){
        
        [self.friendsArray removeObjectAtIndex:[indexPath row]];
        [HUD show:YES];
        
        pagingTokenAdFr += 1;
        [self connectCheckinService:pagingTokenAdFr];
    }else {
    
    tohumProfileViewController * profileView= [[tohumProfileViewController alloc] initWithNibName:@"tohumProfileViewController" bundle:nil];
    profileView.isFriend = [user IsFriend];
    profileView.friendID = [user ID_];
    [profileView setTitle:[user name]];
    tohumAppDelegate *objAppDelegate=(tohumAppDelegate *)[[UIApplication sharedApplication] delegate];
    [objAppDelegate.navController2 pushViewController:profileView animated:YES];
    }
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.friendsArray count];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 70;
}
- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath{
    //put data on your array
    //[tableView reloadData];
    
    NSLog(@"%d", [indexPath row]);
}
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *simpleTableIdentifier = @"FriendsCustomCell";
    
    tohumFriendsCustomCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    
    CheckinAward_User *user = [self.friendsArray objectAtIndex:[indexPath row]];
    
    if (cell == nil) {
        NSArray *nib = [[NSBundle mainBundle] loadNibNamed:@"FriendsCustomCell" owner:self options:nil];
        for(id currentObject in nib)
        {
            if([currentObject isKindOfClass:[tohumFriendsCustomCell class]])
            {
                cell = (tohumFriendsCustomCell *)currentObject;
                break;
            }
        }
        
    }
    if (user.CA_personPhotoUrl != NULL)
    {
        //picture BAŞ...
        [Base64 initialize];
        NSString *str = user.CA_personPhotoUrl;
        NSData * data = [Base64 decode:str];
        cell.userPicture.image = [UIImage imageWithData:data];
        //Picture SON...
    }else {
        cell.userPicture.image = [UIImage imageNamed:@"default_profile.jpg"];
    }
    cell.userName.text = [NSString stringWithFormat:@"%@ %@",user.name,user.surname];
    cell.AwardsPicture.image = NULL;
    cell.AwardsDetail.text = NULL;
    cell.dateLabel.text = NULL;
    cell.CommentsLabel.text = NULL;
    
    if ([user.ID_ isEqualToNumber:[NSNumber numberWithInt:-1]]){
        cell.userPicture.image = Nil;
        cell.AwardsPicture.image = Nil;
    }
    
    return cell;
}

- (void) connectCheckinService:(NSInteger) token{

    tohumPlistControl *control = [[tohumPlistControl alloc] init];
    
    tohumAppDelegate * appDelegate = [[tohumAppDelegate alloc] init];
    CheckinAwardSoap12Binding *binding = [appDelegate Soap12Binding];
    
    CheckinAward_CA_GetPerson *person = [[CheckinAward_CA_GetPerson alloc] init];
    person.key = searchBarText;
    person.pagingToken = [NSNumber numberWithInt:token];
    person.ownerID = [control getUserIDnumber];
    
    
    
    [binding CA_GetPersonAsyncUsingParameters:person delegate:self];
	[HUD show:YES];
}

- (void)searchBarTextDidBeginEditing:(UISearchBar *)searchBar {
    [searchBar setShowsCancelButton:YES animated:YES];
    //self.theTableView.allowsSelection = NO;
    //self.theTableView.scrollEnabled = NO;
}
- (void)searchBarCancelButtonClicked:(UISearchBar *)searchBar {
    searchBar.text=@"";
    
    [searchBar setShowsCancelButton:NO animated:YES];
    [searchBar resignFirstResponder];
    [self.friendsArray removeAllObjects];
    [_friendsTable reloadData];
    //self.theTableView.allowsSelection = YES;
    //self.theTableView.scrollEnabled = YES;
}
- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar {
    // You'll probably want to do this on another thread
    // SomeService is just a dummy class representing some
    // api that you are using to do the search
	
    [self.friendsArray removeAllObjects];
    [self.friendsTable reloadData];
    
    searchBarText = searchBar.text;
    
    [searchBar setShowsCancelButton:NO animated:YES];
    [searchBar resignFirstResponder];
    
    [self connectCheckinService:pagingTokenAdFr];
}
- (void) operation:(CheckinAwardSoap12BindingOperation *)operation completedWithResponse:(CheckinAwardSoap12BindingResponse *)response{
    
    for (id mine in response.bodyParts){
        if ([mine isKindOfClass:[CheckinAward_CA_GetPersonResponse class]]){
            
            id personResult = [mine CA_GetPersonResult];
            id people = [personResult CA_People];
            id user = [people User];
            
            objectCountAdFr = [[personResult CA_PersonCount] integerValue];
            
            for (id comp in user){
                CheckinAward_User *person = [[CheckinAward_User alloc] init];
                person = comp;
                
                [self.friendsArray addObject:person];
                [_friendsTable reloadData];
            }
            if (objectCountAdFr == 10){
                
                CheckinAward_User *user = [[CheckinAward_User alloc] init];
                user.name = @"Load More...";
                user.ID_ = [NSNumber numberWithInt:-1];
                [self.friendsArray addObject:user];
                [self.friendsTable reloadData];
            }
            
        }
    }
    [HUD hide:YES];
}
@end
