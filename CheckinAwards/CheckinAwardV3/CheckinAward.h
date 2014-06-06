#import <Foundation/Foundation.h>
#import "USAdditions.h"
#import <libxml/tree.h>
#import "USGlobals.h"
@class CheckinAward_TestConnection;
@class CheckinAward_TestConnectionResponse;
@class CheckinAward_SignUp;
@class CheckinAward_User;
@class CheckinAward_Base;
@class CheckinAward_SignUpResponse;
@class CheckinAward_Login;
@class CheckinAward_LoginResponse;
@class CheckinAward_Logout;
@class CheckinAward_LogoutResponse;
@class CheckinAward_CA_AddPersonalInfo;
@class CheckinAward_CA_AddPersonalInfoResponse;
@class CheckinAward_GetPersonalInfo;
@class CheckinAward_GetPersonalInfoResponse;
@class CheckinAward_CA_PersonalInfo;
@class CheckinAward_GetCompaniesNearby;
@class CheckinAward_LatLng;
@class CheckinAward_GetCompaniesNearbyResponse;
@class CheckinAward_ArrayOfCompany;
@class CheckinAward_Company;
@class CheckinAward_Campaign;
@class CheckinAward_Checkin;
@class CheckinAward_CheckinResponse;
@class CheckinAward_CA_CheckinResult;
@class CheckinAward_CA_GetPersonalCheckins;
@class CheckinAward_CA_GetPersonalCheckinsResponse;
@class CheckinAward_CA_PersonalCheckinCollection;
@class CheckinAward_ArrayOfCA_PersonalCheckin;
@class CheckinAward_CA_PersonalCheckin;
@class CheckinAward_CA_GetPersonalRank;
@class CheckinAward_CA_GetPersonalRankResponse;
@class CheckinAward_CA_AddRank;
@class CheckinAward_CA_AddRankResponse;
@class CheckinAward_CA_AddComment;
@class CheckinAward_CA_AddCommentResponse;
@class CheckinAward_CA_GetComment;
@class CheckinAward_CA_GetCommentResponse;
@class CheckinAward_CA_CommentLikeEntry;
@class CheckinAward_CA_AddLike;
@class CheckinAward_CA_AddLikeResponse;
@class CheckinAward_CA_GetLike;
@class CheckinAward_CA_GetLikeResponse;
@class CheckinAward_CA_GetPerson;
@class CheckinAward_CA_GetPersonResponse;
@class CheckinAward_CA_PeopleCollection;
@class CheckinAward_ArrayOfUser;
@class CheckinAward_AddAsFriend;
@class CheckinAward_AddAsFriendResponse;
@class CheckinAward_DeleteFriend;
@class CheckinAward_DeleteFriendResponse;
@class CheckinAward_SelfWall;
@class CheckinAward_SelfWallResponse;
@class CheckinAward_GetAllFriends;
@class CheckinAward_GetAllFriendsResponse;
@interface CheckinAward_TestConnection : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_TestConnection *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_TestConnectionResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_TestConnectionResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_Base : NSObject {
	
/* elements */
	NSNumber * ID_;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_Base *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * ID_;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_User : CheckinAward_Base {
	
/* elements */
	NSString * userName;
	NSString * name;
	NSString * surname;
	NSString * eMail;
	NSString * password;
	USBoolean * IsOnline;
	NSString * CA_personPhotoUrl;
	USBoolean * IsFriend;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_User *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * userName;
@property (retain) NSString * name;
@property (retain) NSString * surname;
@property (retain) NSString * eMail;
@property (retain) NSString * password;
@property (retain) USBoolean * IsOnline;
@property (retain) NSString * CA_personPhotoUrl;
@property (retain) USBoolean * IsFriend;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_SignUp : NSObject {
	
/* elements */
	CheckinAward_User * insertUser;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_SignUp *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_User * insertUser;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_SignUpResponse : NSObject {
	
/* elements */
	CheckinAward_User * SignUpResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_SignUpResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_User * SignUpResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_Login : NSObject {
	
/* elements */
	NSString * userName;
	NSString * password;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_Login *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * userName;
@property (retain) NSString * password;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_LoginResponse : NSObject {
	
/* elements */
	CheckinAward_User * LoginResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_LoginResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_User * LoginResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_Logout : NSObject {
	
/* elements */
	NSString * userName;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_Logout *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * userName;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_LogoutResponse : NSObject {
	
/* elements */
	USBoolean * LogoutResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_LogoutResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) USBoolean * LogoutResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_AddPersonalInfo : NSObject {
	
/* elements */
	NSNumber * userID;
	NSString * profilePhoto;
	NSDate * birthDate;
	NSString * name;
	NSString * surname;
	NSString * email;
	USBoolean * isFemale;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_AddPersonalInfo *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * userID;
@property (retain) NSString * profilePhoto;
@property (retain) NSDate * birthDate;
@property (retain) NSString * name;
@property (retain) NSString * surname;
@property (retain) NSString * email;
@property (retain) USBoolean * isFemale;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_AddPersonalInfoResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_AddPersonalInfoResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_GetPersonalInfo : NSObject {
	
/* elements */
	NSNumber * owneruserID;
	NSNumber * userID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_GetPersonalInfo *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * owneruserID;
@property (retain) NSNumber * userID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_PersonalInfo : CheckinAward_User {
	
/* elements */
	NSDate * BirthDate;
	USBoolean * IsFemale;
	CheckinAward_User * CurrentUser;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_PersonalInfo *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSDate * BirthDate;
@property (retain) USBoolean * IsFemale;
@property (retain) CheckinAward_User * CurrentUser;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_GetPersonalInfoResponse : NSObject {
	
/* elements */
	CheckinAward_CA_PersonalInfo * GetPersonalInfoResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_GetPersonalInfoResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_CA_PersonalInfo * GetPersonalInfoResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_LatLng : NSObject {
	
/* elements */
	NSNumber * C_X;
	NSNumber * C_Y;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_LatLng *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * C_X;
@property (retain) NSNumber * C_Y;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_GetCompaniesNearby : NSObject {
	
/* elements */
	CheckinAward_LatLng * Coordinates;
	NSNumber * maxCount;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_GetCompaniesNearby *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_LatLng * Coordinates;
@property (retain) NSNumber * maxCount;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_Campaign : NSObject {
	
/* elements */
	NSString * CampaignImageURL;
	NSString * CampaignText;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_Campaign *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * CampaignImageURL;
@property (retain) NSString * CampaignText;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_Company : CheckinAward_Base {
	
/* elements */
	CheckinAward_LatLng * Coordinates;
	CheckinAward_Campaign * CompanyCampaign;
	NSString * CompanyName;
	NSString * CompanyImageURL;
	NSString * CompanyEmail;
	NSString * Password;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_Company *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_LatLng * Coordinates;
@property (retain) CheckinAward_Campaign * CompanyCampaign;
@property (retain) NSString * CompanyName;
@property (retain) NSString * CompanyImageURL;
@property (retain) NSString * CompanyEmail;
@property (retain) NSString * Password;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_ArrayOfCompany : NSObject {
	
/* elements */
	NSMutableArray *Company;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_ArrayOfCompany *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addCompany:(CheckinAward_Company *)toAdd;
@property (readonly) NSMutableArray * Company;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_GetCompaniesNearbyResponse : NSObject {
	
/* elements */
	CheckinAward_ArrayOfCompany * GetCompaniesNearbyResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_GetCompaniesNearbyResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_ArrayOfCompany * GetCompaniesNearbyResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_Checkin : NSObject {
	
/* elements */
	NSNumber * CompanyID;
	NSNumber * UserID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_Checkin *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * CompanyID;
@property (retain) NSNumber * UserID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_CheckinResult : CheckinAward_Base {
	
/* elements */
	USBoolean * CA_IsAwarded;
	USBoolean * CA_CheckinSuccess;
	NSString * CA_AwardCode;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_CheckinResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) USBoolean * CA_IsAwarded;
@property (retain) USBoolean * CA_CheckinSuccess;
@property (retain) NSString * CA_AwardCode;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CheckinResponse : NSObject {
	
/* elements */
	CheckinAward_CA_CheckinResult * CheckinResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CheckinResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_CA_CheckinResult * CheckinResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_GetPersonalCheckins : NSObject {
	
/* elements */
	NSNumber * CA_userID;
	NSNumber * CA_pagingToken;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_GetPersonalCheckins *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * CA_userID;
@property (retain) NSNumber * CA_pagingToken;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_PersonalCheckin : CheckinAward_Base {
	
/* elements */
	CheckinAward_Company * CA_CheckedInCompany;
	CheckinAward_User * CA_CheckedInUser;
	NSDate * CheckInDate;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_PersonalCheckin *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_Company * CA_CheckedInCompany;
@property (retain) CheckinAward_User * CA_CheckedInUser;
@property (retain) NSDate * CheckInDate;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_ArrayOfCA_PersonalCheckin : NSObject {
	
/* elements */
	NSMutableArray *CA_PersonalCheckin;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_ArrayOfCA_PersonalCheckin *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addCA_PersonalCheckin:(CheckinAward_CA_PersonalCheckin *)toAdd;
@property (readonly) NSMutableArray * CA_PersonalCheckin;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_PersonalCheckinCollection : NSObject {
	
/* elements */
	CheckinAward_ArrayOfCA_PersonalCheckin * CA_CheckInCollection;
	NSNumber * CA_objectCount;
	NSNumber * CA_pagingToken;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_PersonalCheckinCollection *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_ArrayOfCA_PersonalCheckin * CA_CheckInCollection;
@property (retain) NSNumber * CA_objectCount;
@property (retain) NSNumber * CA_pagingToken;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_GetPersonalCheckinsResponse : NSObject {
	
/* elements */
	CheckinAward_CA_PersonalCheckinCollection * CA_GetPersonalCheckinsResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_GetPersonalCheckinsResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_CA_PersonalCheckinCollection * CA_GetPersonalCheckinsResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_GetPersonalRank : NSObject {
	
/* elements */
	NSString * CA_userName;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_GetPersonalRank *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * CA_userName;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_GetPersonalRankResponse : NSObject {
	
/* elements */
	NSNumber * CA_GetPersonalRankResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_GetPersonalRankResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * CA_GetPersonalRankResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_AddRank : NSObject {
	
/* elements */
	NSString * userName;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_AddRank *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * userName;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_AddRankResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_AddRankResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_AddComment : NSObject {
	
/* elements */
	NSNumber * CA_commentOwnerID;
	NSNumber * CA_commented_post_ID;
	NSString * comment;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_AddComment *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * CA_commentOwnerID;
@property (retain) NSNumber * CA_commented_post_ID;
@property (retain) NSString * comment;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_AddCommentResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_AddCommentResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_GetComment : NSObject {
	
/* elements */
	NSString * CA_post_id;
	NSNumber * pagingToken;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_GetComment *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * CA_post_id;
@property (retain) NSNumber * pagingToken;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_CommentLikeEntry : CheckinAward_Base {
	
/* elements */
	CheckinAward_User * CA_CommentLikeOwner;
	NSString * CA_post_id;
	USBoolean * CA_IsComment;
	NSString * CA_Comment;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_CommentLikeEntry *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_User * CA_CommentLikeOwner;
@property (retain) NSString * CA_post_id;
@property (retain) USBoolean * CA_IsComment;
@property (retain) NSString * CA_Comment;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_GetCommentResponse : NSObject {
	
/* elements */
	CheckinAward_CA_CommentLikeEntry * CA_GetCommentResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_GetCommentResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_CA_CommentLikeEntry * CA_GetCommentResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_AddLike : NSObject {
	
/* elements */
	NSString * CA_likeOwner_username;
	NSString * CA_liked_post;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_AddLike *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * CA_likeOwner_username;
@property (retain) NSString * CA_liked_post;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_AddLikeResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_AddLikeResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_GetLike : NSObject {
	
/* elements */
	NSString * CA_post_id;
	NSNumber * pagingToken;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_GetLike *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * CA_post_id;
@property (retain) NSNumber * pagingToken;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_GetLikeResponse : NSObject {
	
/* elements */
	NSString * CA_GetLikeResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_GetLikeResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * CA_GetLikeResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_GetPerson : NSObject {
	
/* elements */
	NSNumber * ownerID;
	NSString * key;
	NSNumber * pagingToken;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_GetPerson *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * ownerID;
@property (retain) NSString * key;
@property (retain) NSNumber * pagingToken;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_ArrayOfUser : NSObject {
	
/* elements */
	NSMutableArray *User;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_ArrayOfUser *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addUser:(CheckinAward_User *)toAdd;
@property (readonly) NSMutableArray * User;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_PeopleCollection : NSObject {
	
/* elements */
	CheckinAward_ArrayOfUser * CA_People;
	NSNumber * CA_PersonCount;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_PeopleCollection *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_ArrayOfUser * CA_People;
@property (retain) NSNumber * CA_PersonCount;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_CA_GetPersonResponse : NSObject {
	
/* elements */
	CheckinAward_CA_PeopleCollection * CA_GetPersonResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_CA_GetPersonResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_CA_PeopleCollection * CA_GetPersonResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_AddAsFriend : NSObject {
	
/* elements */
	NSNumber * ownerUserID;
	NSNumber * friendID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_AddAsFriend *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * ownerUserID;
@property (retain) NSNumber * friendID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_AddAsFriendResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_AddAsFriendResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_DeleteFriend : NSObject {
	
/* elements */
	NSNumber * ownerUserID;
	NSNumber * friendID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_DeleteFriend *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * ownerUserID;
@property (retain) NSNumber * friendID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_DeleteFriendResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_DeleteFriendResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_SelfWall : NSObject {
	
/* elements */
	NSNumber * ownerUserID;
	NSNumber * token;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_SelfWall *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * ownerUserID;
@property (retain) NSNumber * token;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_SelfWallResponse : NSObject {
	
/* elements */
	CheckinAward_CA_PersonalCheckinCollection * SelfWallResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_SelfWallResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_CA_PersonalCheckinCollection * SelfWallResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_GetAllFriends : NSObject {
	
/* elements */
	NSNumber * ownerUserID;
	NSNumber * token;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_GetAllFriends *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * ownerUserID;
@property (retain) NSNumber * token;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CheckinAward_GetAllFriendsResponse : NSObject {
	
/* elements */
	CheckinAward_CA_PeopleCollection * GetAllFriendsResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CheckinAward_GetAllFriendsResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) CheckinAward_CA_PeopleCollection * GetAllFriendsResult;
/* attributes */
- (NSDictionary *)attributes;
@end
/* Cookies handling provided by http://en.wikibooks.org/wiki/Programming:WebObjects/Web_Services/Web_Service_Provider */
#import <libxml/parser.h>
#import "xsd.h"
#import "CheckinAward.h"
@class CheckinAwardSoapBinding;
@class CheckinAwardSoap12Binding;
@interface CheckinAward : NSObject {
	
}
+ (CheckinAwardSoapBinding *)CheckinAwardSoapBinding;
+ (CheckinAwardSoap12Binding *)CheckinAwardSoap12Binding;
@end
@class CheckinAwardSoapBindingResponse;
@class CheckinAwardSoapBindingOperation;
@protocol CheckinAwardSoapBindingResponseDelegate <NSObject>
- (void) operation:(CheckinAwardSoapBindingOperation *)operation completedWithResponse:(CheckinAwardSoapBindingResponse *)response;
@end
@interface CheckinAwardSoapBinding : NSObject <CheckinAwardSoapBindingResponseDelegate> {
	NSURL *address;
	NSTimeInterval defaultTimeout;
	NSMutableArray *cookies;
	BOOL logXMLInOut;
	BOOL synchronousOperationComplete;
	NSString *authUsername;
	NSString *authPassword;
}
@property (copy) NSURL *address;
@property (assign) BOOL logXMLInOut;
@property (assign) NSTimeInterval defaultTimeout;
@property (nonatomic, retain) NSMutableArray *cookies;
@property (nonatomic, retain) NSString *authUsername;
@property (nonatomic, retain) NSString *authPassword;
- (id)initWithAddress:(NSString *)anAddress;
- (void)sendHTTPCallUsingBody:(NSString *)body soapAction:(NSString *)soapAction forOperation:(CheckinAwardSoapBindingOperation *)operation;
- (void)addCookie:(NSHTTPCookie *)toAdd;
- (CheckinAwardSoapBindingResponse *)TestConnectionUsingParameters:(CheckinAward_TestConnection *)aParameters ;
- (void)TestConnectionAsyncUsingParameters:(CheckinAward_TestConnection *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)SignUpUsingParameters:(CheckinAward_SignUp *)aParameters ;
- (void)SignUpAsyncUsingParameters:(CheckinAward_SignUp *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)LoginUsingParameters:(CheckinAward_Login *)aParameters ;
- (void)LoginAsyncUsingParameters:(CheckinAward_Login *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)LogoutUsingParameters:(CheckinAward_Logout *)aParameters ;
- (void)LogoutAsyncUsingParameters:(CheckinAward_Logout *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)CA_AddPersonalInfoUsingParameters:(CheckinAward_CA_AddPersonalInfo *)aParameters ;
- (void)CA_AddPersonalInfoAsyncUsingParameters:(CheckinAward_CA_AddPersonalInfo *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)GetPersonalInfoUsingParameters:(CheckinAward_GetPersonalInfo *)aParameters ;
- (void)GetPersonalInfoAsyncUsingParameters:(CheckinAward_GetPersonalInfo *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)GetCompaniesNearbyUsingParameters:(CheckinAward_GetCompaniesNearby *)aParameters ;
- (void)GetCompaniesNearbyAsyncUsingParameters:(CheckinAward_GetCompaniesNearby *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)CheckinUsingParameters:(CheckinAward_Checkin *)aParameters ;
- (void)CheckinAsyncUsingParameters:(CheckinAward_Checkin *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)CA_GetPersonalCheckinsUsingParameters:(CheckinAward_CA_GetPersonalCheckins *)aParameters ;
- (void)CA_GetPersonalCheckinsAsyncUsingParameters:(CheckinAward_CA_GetPersonalCheckins *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)CA_GetPersonalRankUsingParameters:(CheckinAward_CA_GetPersonalRank *)aParameters ;
- (void)CA_GetPersonalRankAsyncUsingParameters:(CheckinAward_CA_GetPersonalRank *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)CA_AddRankUsingParameters:(CheckinAward_CA_AddRank *)aParameters ;
- (void)CA_AddRankAsyncUsingParameters:(CheckinAward_CA_AddRank *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)CA_AddCommentUsingParameters:(CheckinAward_CA_AddComment *)aParameters ;
- (void)CA_AddCommentAsyncUsingParameters:(CheckinAward_CA_AddComment *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)CA_GetCommentUsingParameters:(CheckinAward_CA_GetComment *)aParameters ;
- (void)CA_GetCommentAsyncUsingParameters:(CheckinAward_CA_GetComment *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)CA_AddLikeUsingParameters:(CheckinAward_CA_AddLike *)aParameters ;
- (void)CA_AddLikeAsyncUsingParameters:(CheckinAward_CA_AddLike *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)CA_GetLikeUsingParameters:(CheckinAward_CA_GetLike *)aParameters ;
- (void)CA_GetLikeAsyncUsingParameters:(CheckinAward_CA_GetLike *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)CA_GetPersonUsingParameters:(CheckinAward_CA_GetPerson *)aParameters ;
- (void)CA_GetPersonAsyncUsingParameters:(CheckinAward_CA_GetPerson *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)AddAsFriendUsingParameters:(CheckinAward_AddAsFriend *)aParameters ;
- (void)AddAsFriendAsyncUsingParameters:(CheckinAward_AddAsFriend *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)DeleteFriendUsingParameters:(CheckinAward_DeleteFriend *)aParameters ;
- (void)DeleteFriendAsyncUsingParameters:(CheckinAward_DeleteFriend *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)SelfWallUsingParameters:(CheckinAward_SelfWall *)aParameters ;
- (void)SelfWallAsyncUsingParameters:(CheckinAward_SelfWall *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoapBindingResponse *)GetAllFriendsUsingParameters:(CheckinAward_GetAllFriends *)aParameters ;
- (void)GetAllFriendsAsyncUsingParameters:(CheckinAward_GetAllFriends *)aParameters  delegate:(id<CheckinAwardSoapBindingResponseDelegate>)responseDelegate;
@end
@interface CheckinAwardSoapBindingOperation : NSOperation {
	CheckinAwardSoapBinding *binding;
	CheckinAwardSoapBindingResponse *response;
	id<CheckinAwardSoapBindingResponseDelegate> delegate;
	NSMutableData *responseData;
	NSURLConnection *urlConnection;
}
@property (retain) CheckinAwardSoapBinding *binding;
@property (readonly) CheckinAwardSoapBindingResponse *response;
@property (nonatomic, assign) id<CheckinAwardSoapBindingResponseDelegate> delegate;
@property (nonatomic, retain) NSMutableData *responseData;
@property (nonatomic, retain) NSURLConnection *urlConnection;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate;
@end
@interface CheckinAwardSoapBinding_TestConnection : CheckinAwardSoapBindingOperation {
	CheckinAward_TestConnection * parameters;
}
@property (retain) CheckinAward_TestConnection * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_TestConnection *)aParameters
;
@end
@interface CheckinAwardSoapBinding_SignUp : CheckinAwardSoapBindingOperation {
	CheckinAward_SignUp * parameters;
}
@property (retain) CheckinAward_SignUp * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_SignUp *)aParameters
;
@end
@interface CheckinAwardSoapBinding_Login : CheckinAwardSoapBindingOperation {
	CheckinAward_Login * parameters;
}
@property (retain) CheckinAward_Login * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_Login *)aParameters
;
@end
@interface CheckinAwardSoapBinding_Logout : CheckinAwardSoapBindingOperation {
	CheckinAward_Logout * parameters;
}
@property (retain) CheckinAward_Logout * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_Logout *)aParameters
;
@end
@interface CheckinAwardSoapBinding_CA_AddPersonalInfo : CheckinAwardSoapBindingOperation {
	CheckinAward_CA_AddPersonalInfo * parameters;
}
@property (retain) CheckinAward_CA_AddPersonalInfo * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_AddPersonalInfo *)aParameters
;
@end
@interface CheckinAwardSoapBinding_GetPersonalInfo : CheckinAwardSoapBindingOperation {
	CheckinAward_GetPersonalInfo * parameters;
}
@property (retain) CheckinAward_GetPersonalInfo * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_GetPersonalInfo *)aParameters
;
@end
@interface CheckinAwardSoapBinding_GetCompaniesNearby : CheckinAwardSoapBindingOperation {
	CheckinAward_GetCompaniesNearby * parameters;
}
@property (retain) CheckinAward_GetCompaniesNearby * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_GetCompaniesNearby *)aParameters
;
@end
@interface CheckinAwardSoapBinding_Checkin : CheckinAwardSoapBindingOperation {
	CheckinAward_Checkin * parameters;
}
@property (retain) CheckinAward_Checkin * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_Checkin *)aParameters
;
@end
@interface CheckinAwardSoapBinding_CA_GetPersonalCheckins : CheckinAwardSoapBindingOperation {
	CheckinAward_CA_GetPersonalCheckins * parameters;
}
@property (retain) CheckinAward_CA_GetPersonalCheckins * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_GetPersonalCheckins *)aParameters
;
@end
@interface CheckinAwardSoapBinding_CA_GetPersonalRank : CheckinAwardSoapBindingOperation {
	CheckinAward_CA_GetPersonalRank * parameters;
}
@property (retain) CheckinAward_CA_GetPersonalRank * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_GetPersonalRank *)aParameters
;
@end
@interface CheckinAwardSoapBinding_CA_AddRank : CheckinAwardSoapBindingOperation {
	CheckinAward_CA_AddRank * parameters;
}
@property (retain) CheckinAward_CA_AddRank * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_AddRank *)aParameters
;
@end
@interface CheckinAwardSoapBinding_CA_AddComment : CheckinAwardSoapBindingOperation {
	CheckinAward_CA_AddComment * parameters;
}
@property (retain) CheckinAward_CA_AddComment * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_AddComment *)aParameters
;
@end
@interface CheckinAwardSoapBinding_CA_GetComment : CheckinAwardSoapBindingOperation {
	CheckinAward_CA_GetComment * parameters;
}
@property (retain) CheckinAward_CA_GetComment * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_GetComment *)aParameters
;
@end
@interface CheckinAwardSoapBinding_CA_AddLike : CheckinAwardSoapBindingOperation {
	CheckinAward_CA_AddLike * parameters;
}
@property (retain) CheckinAward_CA_AddLike * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_AddLike *)aParameters
;
@end
@interface CheckinAwardSoapBinding_CA_GetLike : CheckinAwardSoapBindingOperation {
	CheckinAward_CA_GetLike * parameters;
}
@property (retain) CheckinAward_CA_GetLike * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_GetLike *)aParameters
;
@end
@interface CheckinAwardSoapBinding_CA_GetPerson : CheckinAwardSoapBindingOperation {
	CheckinAward_CA_GetPerson * parameters;
}
@property (retain) CheckinAward_CA_GetPerson * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_GetPerson *)aParameters
;
@end
@interface CheckinAwardSoapBinding_AddAsFriend : CheckinAwardSoapBindingOperation {
	CheckinAward_AddAsFriend * parameters;
}
@property (retain) CheckinAward_AddAsFriend * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_AddAsFriend *)aParameters
;
@end
@interface CheckinAwardSoapBinding_DeleteFriend : CheckinAwardSoapBindingOperation {
	CheckinAward_DeleteFriend * parameters;
}
@property (retain) CheckinAward_DeleteFriend * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_DeleteFriend *)aParameters
;
@end
@interface CheckinAwardSoapBinding_SelfWall : CheckinAwardSoapBindingOperation {
	CheckinAward_SelfWall * parameters;
}
@property (retain) CheckinAward_SelfWall * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_SelfWall *)aParameters
;
@end
@interface CheckinAwardSoapBinding_GetAllFriends : CheckinAwardSoapBindingOperation {
	CheckinAward_GetAllFriends * parameters;
}
@property (retain) CheckinAward_GetAllFriends * parameters;
- (id)initWithBinding:(CheckinAwardSoapBinding *)aBinding delegate:(id<CheckinAwardSoapBindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_GetAllFriends *)aParameters
;
@end
@interface CheckinAwardSoapBinding_envelope : NSObject {
}
+ (CheckinAwardSoapBinding_envelope *)sharedInstance;
- (NSString *)serializedFormUsingHeaderElements:(NSDictionary *)headerElements bodyElements:(NSDictionary *)bodyElements;
@end
@interface CheckinAwardSoapBindingResponse : NSObject {
	NSArray *headers;
	NSArray *bodyParts;
	NSError *error;
}
@property (retain) NSArray *headers;
@property (retain) NSArray *bodyParts;
@property (retain) NSError *error;
@end
@class CheckinAwardSoap12BindingResponse;
@class CheckinAwardSoap12BindingOperation;
@protocol CheckinAwardSoap12BindingResponseDelegate <NSObject>
- (void) operation:(CheckinAwardSoap12BindingOperation *)operation completedWithResponse:(CheckinAwardSoap12BindingResponse *)response;
@end
@interface CheckinAwardSoap12Binding : NSObject <CheckinAwardSoap12BindingResponseDelegate> {
	NSURL *address;
	NSTimeInterval defaultTimeout;
	NSMutableArray *cookies;
	BOOL logXMLInOut;
	BOOL synchronousOperationComplete;
	NSString *authUsername;
	NSString *authPassword;
}
@property (copy) NSURL *address;
@property (assign) BOOL logXMLInOut;
@property (assign) NSTimeInterval defaultTimeout;
@property (nonatomic, retain) NSMutableArray *cookies;
@property (nonatomic, retain) NSString *authUsername;
@property (nonatomic, retain) NSString *authPassword;
- (id)initWithAddress:(NSString *)anAddress;
- (void)sendHTTPCallUsingBody:(NSString *)body soapAction:(NSString *)soapAction forOperation:(CheckinAwardSoap12BindingOperation *)operation;
- (void)addCookie:(NSHTTPCookie *)toAdd;
- (CheckinAwardSoap12BindingResponse *)TestConnectionUsingParameters:(CheckinAward_TestConnection *)aParameters ;
- (void)TestConnectionAsyncUsingParameters:(CheckinAward_TestConnection *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)SignUpUsingParameters:(CheckinAward_SignUp *)aParameters ;
- (void)SignUpAsyncUsingParameters:(CheckinAward_SignUp *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)LoginUsingParameters:(CheckinAward_Login *)aParameters ;
- (void)LoginAsyncUsingParameters:(CheckinAward_Login *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)LogoutUsingParameters:(CheckinAward_Logout *)aParameters ;
- (void)LogoutAsyncUsingParameters:(CheckinAward_Logout *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)CA_AddPersonalInfoUsingParameters:(CheckinAward_CA_AddPersonalInfo *)aParameters ;
- (void)CA_AddPersonalInfoAsyncUsingParameters:(CheckinAward_CA_AddPersonalInfo *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)GetPersonalInfoUsingParameters:(CheckinAward_GetPersonalInfo *)aParameters ;
- (void)GetPersonalInfoAsyncUsingParameters:(CheckinAward_GetPersonalInfo *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)GetCompaniesNearbyUsingParameters:(CheckinAward_GetCompaniesNearby *)aParameters ;
- (void)GetCompaniesNearbyAsyncUsingParameters:(CheckinAward_GetCompaniesNearby *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)CheckinUsingParameters:(CheckinAward_Checkin *)aParameters ;
- (void)CheckinAsyncUsingParameters:(CheckinAward_Checkin *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)CA_GetPersonalCheckinsUsingParameters:(CheckinAward_CA_GetPersonalCheckins *)aParameters ;
- (void)CA_GetPersonalCheckinsAsyncUsingParameters:(CheckinAward_CA_GetPersonalCheckins *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)CA_GetPersonalRankUsingParameters:(CheckinAward_CA_GetPersonalRank *)aParameters ;
- (void)CA_GetPersonalRankAsyncUsingParameters:(CheckinAward_CA_GetPersonalRank *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)CA_AddRankUsingParameters:(CheckinAward_CA_AddRank *)aParameters ;
- (void)CA_AddRankAsyncUsingParameters:(CheckinAward_CA_AddRank *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)CA_AddCommentUsingParameters:(CheckinAward_CA_AddComment *)aParameters ;
- (void)CA_AddCommentAsyncUsingParameters:(CheckinAward_CA_AddComment *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)CA_GetCommentUsingParameters:(CheckinAward_CA_GetComment *)aParameters ;
- (void)CA_GetCommentAsyncUsingParameters:(CheckinAward_CA_GetComment *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)CA_AddLikeUsingParameters:(CheckinAward_CA_AddLike *)aParameters ;
- (void)CA_AddLikeAsyncUsingParameters:(CheckinAward_CA_AddLike *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)CA_GetLikeUsingParameters:(CheckinAward_CA_GetLike *)aParameters ;
- (void)CA_GetLikeAsyncUsingParameters:(CheckinAward_CA_GetLike *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)CA_GetPersonUsingParameters:(CheckinAward_CA_GetPerson *)aParameters ;
- (void)CA_GetPersonAsyncUsingParameters:(CheckinAward_CA_GetPerson *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)AddAsFriendUsingParameters:(CheckinAward_AddAsFriend *)aParameters ;
- (void)AddAsFriendAsyncUsingParameters:(CheckinAward_AddAsFriend *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)DeleteFriendUsingParameters:(CheckinAward_DeleteFriend *)aParameters ;
- (void)DeleteFriendAsyncUsingParameters:(CheckinAward_DeleteFriend *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)SelfWallUsingParameters:(CheckinAward_SelfWall *)aParameters ;
- (void)SelfWallAsyncUsingParameters:(CheckinAward_SelfWall *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
- (CheckinAwardSoap12BindingResponse *)GetAllFriendsUsingParameters:(CheckinAward_GetAllFriends *)aParameters ;
- (void)GetAllFriendsAsyncUsingParameters:(CheckinAward_GetAllFriends *)aParameters  delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)responseDelegate;
@end
@interface CheckinAwardSoap12BindingOperation : NSOperation {
	CheckinAwardSoap12Binding *binding;
	CheckinAwardSoap12BindingResponse *response;
	id<CheckinAwardSoap12BindingResponseDelegate> delegate;
	NSMutableData *responseData;
	NSURLConnection *urlConnection;
}
@property (retain) CheckinAwardSoap12Binding *binding;
@property (readonly) CheckinAwardSoap12BindingResponse *response;
@property (nonatomic, assign) id<CheckinAwardSoap12BindingResponseDelegate> delegate;
@property (nonatomic, retain) NSMutableData *responseData;
@property (nonatomic, retain) NSURLConnection *urlConnection;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate;
@end
@interface CheckinAwardSoap12Binding_TestConnection : CheckinAwardSoap12BindingOperation {
	CheckinAward_TestConnection * parameters;
}
@property (retain) CheckinAward_TestConnection * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_TestConnection *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_SignUp : CheckinAwardSoap12BindingOperation {
	CheckinAward_SignUp * parameters;
}
@property (retain) CheckinAward_SignUp * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_SignUp *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_Login : CheckinAwardSoap12BindingOperation {
	CheckinAward_Login * parameters;
}
@property (retain) CheckinAward_Login * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_Login *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_Logout : CheckinAwardSoap12BindingOperation {
	CheckinAward_Logout * parameters;
}
@property (retain) CheckinAward_Logout * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_Logout *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_CA_AddPersonalInfo : CheckinAwardSoap12BindingOperation {
	CheckinAward_CA_AddPersonalInfo * parameters;
}
@property (retain) CheckinAward_CA_AddPersonalInfo * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_AddPersonalInfo *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_GetPersonalInfo : CheckinAwardSoap12BindingOperation {
	CheckinAward_GetPersonalInfo * parameters;
}
@property (retain) CheckinAward_GetPersonalInfo * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_GetPersonalInfo *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_GetCompaniesNearby : CheckinAwardSoap12BindingOperation {
	CheckinAward_GetCompaniesNearby * parameters;
}
@property (retain) CheckinAward_GetCompaniesNearby * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_GetCompaniesNearby *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_Checkin : CheckinAwardSoap12BindingOperation {
	CheckinAward_Checkin * parameters;
}
@property (retain) CheckinAward_Checkin * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_Checkin *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_CA_GetPersonalCheckins : CheckinAwardSoap12BindingOperation {
	CheckinAward_CA_GetPersonalCheckins * parameters;
}
@property (retain) CheckinAward_CA_GetPersonalCheckins * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_GetPersonalCheckins *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_CA_GetPersonalRank : CheckinAwardSoap12BindingOperation {
	CheckinAward_CA_GetPersonalRank * parameters;
}
@property (retain) CheckinAward_CA_GetPersonalRank * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_GetPersonalRank *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_CA_AddRank : CheckinAwardSoap12BindingOperation {
	CheckinAward_CA_AddRank * parameters;
}
@property (retain) CheckinAward_CA_AddRank * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_AddRank *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_CA_AddComment : CheckinAwardSoap12BindingOperation {
	CheckinAward_CA_AddComment * parameters;
}
@property (retain) CheckinAward_CA_AddComment * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_AddComment *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_CA_GetComment : CheckinAwardSoap12BindingOperation {
	CheckinAward_CA_GetComment * parameters;
}
@property (retain) CheckinAward_CA_GetComment * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_GetComment *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_CA_AddLike : CheckinAwardSoap12BindingOperation {
	CheckinAward_CA_AddLike * parameters;
}
@property (retain) CheckinAward_CA_AddLike * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_AddLike *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_CA_GetLike : CheckinAwardSoap12BindingOperation {
	CheckinAward_CA_GetLike * parameters;
}
@property (retain) CheckinAward_CA_GetLike * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_GetLike *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_CA_GetPerson : CheckinAwardSoap12BindingOperation {
	CheckinAward_CA_GetPerson * parameters;
}
@property (retain) CheckinAward_CA_GetPerson * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_CA_GetPerson *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_AddAsFriend : CheckinAwardSoap12BindingOperation {
	CheckinAward_AddAsFriend * parameters;
}
@property (retain) CheckinAward_AddAsFriend * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_AddAsFriend *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_DeleteFriend : CheckinAwardSoap12BindingOperation {
	CheckinAward_DeleteFriend * parameters;
}
@property (retain) CheckinAward_DeleteFriend * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_DeleteFriend *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_SelfWall : CheckinAwardSoap12BindingOperation {
	CheckinAward_SelfWall * parameters;
}
@property (retain) CheckinAward_SelfWall * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_SelfWall *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_GetAllFriends : CheckinAwardSoap12BindingOperation {
	CheckinAward_GetAllFriends * parameters;
}
@property (retain) CheckinAward_GetAllFriends * parameters;
- (id)initWithBinding:(CheckinAwardSoap12Binding *)aBinding delegate:(id<CheckinAwardSoap12BindingResponseDelegate>)aDelegate
	parameters:(CheckinAward_GetAllFriends *)aParameters
;
@end
@interface CheckinAwardSoap12Binding_envelope : NSObject {
}
+ (CheckinAwardSoap12Binding_envelope *)sharedInstance;
- (NSString *)serializedFormUsingHeaderElements:(NSDictionary *)headerElements bodyElements:(NSDictionary *)bodyElements;
@end
@interface CheckinAwardSoap12BindingResponse : NSObject {
	NSArray *headers;
	NSArray *bodyParts;
	NSError *error;
}
@property (retain) NSArray *headers;
@property (retain) NSArray *bodyParts;
@property (retain) NSError *error;
@end
