//
//  tohumShowFriendsViewController.m
//  checkin awards
//
//  Created by Hamdi ALTINOK on 13.03.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import "tohumShowFriendsViewController.h"

@interface tohumShowFriendsViewController ()

@end

@implementation tohumShowFriendsViewController
@synthesize friendsArray;

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
    self.friendsArray = [[NSMutableArray alloc] init];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {
    [_friendsTable release];
    [super dealloc];
}

//Table view row selection
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    //table da seçim yapılıp yapıladığını kontrol eder
    NSLog(@"Table view tıklandı");
    
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.friendsArray count];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 70;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *simpleTableIdentifier = @"FriendsCustomCell";
    
    tohumFriendsCustomCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    
    //CheckinAward_Company *company = [self.marka objectAtIndex:[indexPath row]];
    
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
    
    return cell;
}


@end
