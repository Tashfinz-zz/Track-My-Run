//
//  LFUserInfoDataSource.h
//  LFopen
//
//  Created by Dulip Gayan Dasanayaka on 3/12/15.
//  Copyright © 2015 Lifefitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFuser.h"

@protocol LFUserInfoDataSource <NSObject>

@optional
/**
 @discussion Equipment is requesting user information
 This delegate will fire when Equipment needs user information such as weight, height, display name etc

 */
- (LFUser*)didRequestUserInformations;


/**
 @discussion Get LF user information as XML file, console use this data for communicate with LFconnect server
 @result User Info
 */
@optional
- (NSString*)requestUserInfoXML;



@optional
/**
 @discussion Equipment is requesting user information
 This delegate will fire when Equipment needs user information such as weight, height, display name etc
 
 */
- (NSString*)didRequestUserSettings;


@optional
/**
 @discussion User update weight value from console
 This delegate will fire when user update weight from console , unit : Kg
 
 */
- (void)didUserUpdateWeightFromConsole:(double)userWeight;



@optional
/**
 @discussion User add gender value from console
 This delegate will fire when user add gender from console ,
 
 */
- (void)didUserAddGenderFromConsole:(LFUserGender)gender;



@optional
/**
 @discussion User update age value from console
 This delegate will fire when user update age from console ,
 
 */
- (void)didUserUpdateAgeFromConsole:(int)age;
@end
