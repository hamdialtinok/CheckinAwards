//
//  tohumHomeViewController.h
//  CheckinAwardV3
//
//  Created by Hamdi ALTINOK on 10.01.2013.
//  Copyright (c) 2013 Check In Award. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import <CoreLocation/CoreLocation.h>
#import "CheckinAward.h"
#import "tohumAppDelegate.h"
#import "tohumCustomCell.h"
#import <FacebookSDK/FacebookSDK.h>
#import "FBDialog.h"
#import "Facebook.h"
#import "tohumMeViewController.h"
#import "MBProgressHUD.h"

extern const NSString *TabBar_Checkin;
extern const NSString *TabBar_Me;
extern const NSString *TabBar_Wall;
extern const NSString *TabBar_Friends;
@interface tohumHomeViewController : UIViewController <UITableViewDelegate, UITableViewDataSource,CLLocationManagerDelegate,CheckinAwardSoap12BindingResponseDelegate,FBDialogDelegate,MKMapViewDelegate,UITabBarControllerDelegate>{
    CLLocationManager *locationManager;
    NSMutableArray *marka;
    MBProgressHUD *HUD;
    NSMutableArray *HomeCompanyPictures;
    NSMutableArray *HomeAwardPictures;
    
}
@property (retain, nonatomic) CLLocationManager *locationManager;
@property (retain, nonatomic) IBOutlet UITableView *locationTABLE;
@property (retain, nonatomic) NSNumber *latitude;
@property (retain, nonatomic) NSNumber *longitude;
@property (retain, nonatomic) NSString *companyName;
@property (retain, nonatomic) NSMutableArray *marka;
@property (strong, nonatomic) Facebook *facebook;
@property (strong, nonatomic) IBOutlet MKMapView *mapView;
@property (strong, nonatomic) CheckinAward_Company *companyGENEL;
@property (retain, nonatomic) IBOutlet UIView *viewCheckin;

@property (strong, nonatomic) UINavigationController *navController;
@property (strong, nonatomic) UINavigationController *navController2;
@property (strong, nonatomic) UINavigationController *navController3;
@property (strong, nonatomic) UITabBarController *tabController;

@property (retain, nonatomic) NSMutableArray *HomeCompanyPictures;
@property (retain, nonatomic) NSMutableArray *HomeAwardPictures;

@end
