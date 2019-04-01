//
//  LFUser.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 28/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"
#import "LFUnitsManager.h"


@interface LFUser : NSObject
{

    
}

@property (nonatomic, strong) NSString * oauth_token;
@property (nonatomic, strong) NSString * oauth_token_secret;
@property (nonatomic, strong) NSString * password;
@property (nonatomic, strong) NSString * firstName;
@property (nonatomic, strong) NSString * lastName;
@property (nonatomic, strong) NSString * emailAddress;
@property (nonatomic, strong) NSString * userType;
@property (nonatomic) long userId;

@property (nonatomic, strong) NSString * consoleAccessToken;
@property (nonatomic, strong) NSString * consoleSignature;
@property (nonatomic, strong) NSString * consoleTokenSecret;
@property (nonatomic, strong) NSString * userSettingsDetails;
@property (nonatomic, strong) NSString * userInfoDetails;
@property (nonatomic, strong) NSString * userTokenHMAC;

@property (nonatomic, strong) NSString * fbAccessToken;
@property (nonatomic, strong) NSString * fbUserId;
@property (nonatomic, strong) NSDate * fbExpierDate;
@property (nonatomic, strong) NSString * fbImageUrl;

@property (nonatomic, strong) NSString * preferredLanguageCode;
@property (nonatomic, strong) NSString * consoleLanguage;
@property (nonatomic, strong) NSString * pushToken;
@property (nonatomic, strong) NSString * xid;
@property (nonatomic, strong) NSString * pin;
@property (nonatomic, strong) NSString * nickName;
@property (nonatomic, strong) NSString * locationName;
@property (nonatomic, strong) NSString * deleted_gps_workout_id;
@property (nonatomic, strong) NSString * listOfConnectedApps;
@property (nonatomic, strong) NSString * membership_level;

@property (nonatomic, strong) NSDate * dateOfBirth;
@property (nonatomic) NSInteger age;
@property (nonatomic) LFUserGender gender;
@property (nonatomic) double weight;
@property (nonatomic) double height;
@property (nonatomic) double flexibility;
@property (nonatomic) double waistLine;
@property (nonatomic) double strengthValue;
@property (nonatomic) double fatPercentage;
@property (nonatomic) double vo2Max;
@property (nonatomic) double bmi;

@property (nonatomic) BOOL netpulseTOS;
@property (nonatomic) BOOL isAcceptTermsAndPolicy;
@property (nonatomic) BOOL hasFbSharing;
@property (nonatomic) BOOL isReceiveMessages;
@property (nonatomic) BOOL isShareName;
@property (nonatomic) BOOL isShareProfile;
@property (nonatomic) BOOL isShareProgram;
@property (nonatomic) BOOL isShareProgress;
@property (nonatomic) BOOL inWorkoutDisplay;
@property (nonatomic) BOOL outdoorGpsRelay;
@property (nonatomic) BOOL enablePedoMeter;
@property (nonatomic) BOOL isProximityLoginEnable;
@property (nonatomic) BOOL isHealthKitEnable;
@property (nonatomic) BOOL needToSyncWithServer;
@property (nonatomic) BOOL enableProximitySetting;
@property (nonatomic) BOOL emailNotificationAgreement;
@property (nonatomic) BOOL dataMigrated;
@property (nonatomic) BOOL isNetpulseUser;


@property  LFUnitMeasurement heightUnit;
@property  LFUnitMeasurement weightUnit;
@property  LFUnitMeasurement preferredUnit;



- (instancetype)initWithUserData:(NSDictionary*)userData;
- (void)updateUserData:(NSDictionary*)userData authData:(NSDictionary*)authData;

- (NSArray*)getConnectedApps;
- (void)setConnectedApps:(NSArray*)thirdPartyConnectedApps;
- (NSArray *)getListOfDeletedGPSWorkouts;
- (void)setDeletedGPSWorkouts:(NSArray*)deletedGPSWorkoutIds;
@end
