//
//  LFServiceLib.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 22/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "LFWorkoutStream.h"
#import "LFShared.h"
#import "LFWorkout.h"
#import "LFWorkoutEntity.h"
#import "LFQRStrengthWorkout.h"
#import "LFCardioEquipmentWorkoutResult.h"
#import "LFQRworkout.h"
#import "LFEquipmentCapability.h"
#import "LFUser.h"
#import "LFEquipmentConfiguration.h"
#import "LFWorkoutSessionDelegate.h"
#import "LFPresetDataSource.h"
#import "LFUserInfoDataSource.h"


typedef enum LFWorkoutSessionType {
    LFSimulateWorkoutSession,
    LFRealWorkoutSession
} LFWorkoutSessionType;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |																			|
  Class to intereface between LFopen API and the iOS applications.
 |																			|
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
*/
@interface LFEquipmentConnectionManager : NSObject 
{

}

@property (nonatomic, strong) id<LFPresetDataSource> presetDataSource;
@property (nonatomic, strong) id<LFUserInfoDataSource> userInfoDataSource;




+ (instancetype)sharedManager;

/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |																			|
  Provide instance of LFEquipmentConnectionManager

 |																			|
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)registerForWorkoutSession:(id<LFWorkoutSessionDelegate>)workoutDelegate
                      sessionType:(LFWorkoutSessionType)sessionType;


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |																			          |
  Register for workout session with <LFWorkoutSessionDelegate> delegate
  sessionType  :  simulation mode of LFopen workout session / connect to real equipment
  licenseStatus : LFopen license key status true or false
 |																			          |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)registerForWorkoutSession:(id<LFWorkoutSessionDelegate>)workoutDelegate
                     sessionType:(LFWorkoutSessionType)sessionType
                    licenseStatus:(void (^)(BOOL isValidLicense , NSError* error))licenseStatus;


#pragma mark - Equipment informations

/*
 *Returns Equipment capabilitys based on QR informations
 */
-(LFEquipmentCapability*)parseEquipmentCapability:(NSString*)QRcodestring;


#pragma mark - Verify LF Equipment using BLE advertisment

- (BOOL)isLifefitnessEquipment:(NSDictionary*)advertisementData;


#pragma mark - Bluetooth connection method

/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |																			  |
  Connect to equipment using bluetooth
  qr_url  :  url value in side the QR code on equipment screen
  "didFailConnection:(NSError*)error" delegate will fire if any error occured
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */

- (void)connectThroughBluetoothUsingQRvalue:(NSString*)qr_url response:(void (^)(BOOL success,NSError* error))response;


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |																			  |
  Connect to equipment using bluetooth
  equipment_name  :  Name of the equipment
 "didFailConnection:(NSError*)error" delegate will fire if any error occured
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */

- (void)connectThroughBluetoothUsingEquipmentName:(NSString*)equipment_name;


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |																			  |
  Start scaning for LifeFitness equipment which support Bluetooth
  Please listen for this delegate method for have support equipment lists
  - (void)didFindBluetoothSupportEquipments:(NSArray*)lfSupportEquipmentList;
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)startBLEScanForLFEquipment;


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |																			  |
  Stop scaning and clean bluetooth connection
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)stopBLEScanForLFEquipment;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |																			  |
 Disconnect Connection
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)disconnectBluetoothConnection;


#pragma mark - Start Stop parameter

- (void)startWorkout:(void (^)(BOOL successStatus,NSError* error))response;



- (void)stopWorkout:(void (^)(BOOL successStatus,NSError* error))response;



#pragma mark - Write workout parameter


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |																			|
  Set incline of the equipment, send incline value as double to the console.
  The valid incline rage is 0.0 – 15.0 , only accept up to 1 decimal point
  Support under Bluetooth connection = YES
  Support under wire connection      = YES
 |																			|
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */

- (void)setIncline:(double)inclineValue responseStatus:(void (^)(LFWriteAcknowledgeStatus ack , NSError* error))responseStatus;


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |																			  |
  Set Watts value of the equipment, send Watts value as double to the console.
  Support under Bluetooth connection = YES
  Support under wire connection      = YES
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */

- (void)setWatts:(int)wattsValue responseStatus:(void (^)(LFWriteAcknowledgeStatus ack , NSError* error))responseStatus;


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
  Set Target hart rate of the specific workout, send hart rate value as int to
  the console.
  Support under Bluetooth connection = YES
  Support under wire connection      = YES
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */

- (void)setWorkoutTargetHeartRate:(int)targetHeartrateValue responseStatus:(void (^)(LFWriteAcknowledgeStatus ack , NSError* error))responseStatus;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
  Set message to display on equipment scrren
  Support under Bluetooth connection = YES
  Support under wire connection      = YES
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */

- (void)setMessageToDispalyOnEquipmentScreen:(NSString*)message responseStatus:(void (^)(LFWriteAcknowledgeStatus ack , NSError* error))responseStatus;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
  Set workout level
  Support under Bluetooth connection = YES
  Support under wire connection      = YES
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */

- (void)setWorkoutLevel:(int)level responseStatus:(void (^)(LFWriteAcknowledgeStatus ack , NSError* error))responseStatus;


#pragma mark - Read from equipment

///**
// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
// |                                                                            |
//  Read equipment modal
//  Support under Bluetooth connection = YES
//  Support under wire connection      = NO
// |																			  |
// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
// */
//- (void)readEquipmentModel:(void (^)(LFWahooEquipmentModel model,NSError* error))model;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
  Read equipment state
  Support under Bluetooth connection = YES
  Support under wire connection      = NO
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)readEquipmentState:(void (^)(LFEquipmentState eqstate,NSError* error))state;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
  Read equipment state configuration parameters
  Support under Bluetooth connection = YES
  Support under wire connection      = NO
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)readLFEquipmentConfigParameter:(void (^)(LFEquipmentConfiguration * lfconnectParameter ,NSError* error))state;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
  Add preset to equipment
  Support under Bluetooth connection = YES
  Support under wire connection      = NO
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)uploadWorkoutProgram:(LFWorkoutPreset*)preset presetIndex:(int)preset_index response:(void (^)(NSError * error))response;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
 Add presets to equipment
 Support under Bluetooth connection = YES
 Support under wire connection      = NO
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)addPresets:(NSArray*)preset_list  response:(void (^)(NSError * error))response;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
  Start preset on equipment
  Support under Bluetooth connection = YES
  Support under wire connection      = NO
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)startWorkoutProgram:(LFWorkoutPreset*)preset presetIndex:(int)index response:(void (^)(NSError * error))response;




/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
 Add past result for login user, console use this data for display past performence of the user
 Support under Bluetooth connection = YES
 Support under wire connection      = NO
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)writePastWorkoutResult:(NSArray*)result_list response:(void (^)(NSError * error))response;


- (void)addResult:(LFCardioEquipmentWorkoutResult*)resultObj index:(int)indexnumber response:(void (^)(NSError * error))response;



- (void)addResultSummary:(NSString*)resultSummaryJson response:(void (^)(NSError * error))response;


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
 write GPS workout to console
 Support under Bluetooth connection = YES
 Support under wire connection      = NO
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)writeGPSReplayWorkoutsSummary:(NSString*)jsonObject  response:(void (^)(NSError * error))response;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
 Read detail xml file for result, that produce by console;
 Support under Bluetooth connection = YES
 Support under wire connection      = NO
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)readDetailResult:(void (^)(NSString * detailXmlResult, NSError* error))response;




/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
    upload user profile to equipment using whoo service
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)uploadWahooServiceUserProfile:(LFUser*)userProfile response:(void (^)(NSError * error))response;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
 Write wahoo equipment sensor mesurement
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)writeEquipmentSensorMesurement:(int)hr responseStatus:(void (^)(LFWriteAcknowledgeStatus ack , NSError* error))responseStatus;


#pragma mark - Set User Informations

/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                                                   |
  Write Oauth login information to equipment, Equipment directly loging to LFconnect server for user
  Support under Bluetooth connection = YES
  Support under wire connection      = NO
 |																			                         |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)writeOauthLoginInformations:(LFUser*)userObj response:(void (^)(LFWriteAcknowledgeStatus ack, NSError * error))response;


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                                                   |
  set Display name
  Support under Bluetooth connection = YES
  Support under wire connection      = NO
 |																			                         |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)setDisplayName:(NSString*)displayName response:(void (^)(LFWriteAcknowledgeStatus ack, NSError * error))response;


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                                                   |
  set Age
  Support under Bluetooth connection = YES
  Support under wire connection      = NO
 |																			                         |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)setAge:(int)age response:(void (^)(LFWriteAcknowledgeStatus ack, NSError * error))response;


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                                                   |
  set Gender
  Support under Bluetooth connection = YES
  Support under wire connection      = NO
 |																			                         |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)setGender:(LFUserGender)gender response:(void (^)(LFWriteAcknowledgeStatus ack, NSError * error))response; //m or f


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                                                   |
  set preferred language
  Support under Bluetooth connection = YES
  Support under wire connection      = NO
 |																			                         |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)setLanguage:(NSString *)language_code response:(void (^)(LFWriteAcknowledgeStatus ack, NSError * error))response;; // en,it,fr


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                                                   |
 set preferred unit
 Support under Bluetooth connection = YES
 Support under wire connection      = NO
 |																			                         |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)setUnit:(LFUnitMeasurement)unit response:(void (^)(LFWriteAcknowledgeStatus ack, NSError * error))response;// m-metric, i- imperial


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                                                   |
 set display settings
 Support under Bluetooth connection = YES
 Support under wire connection      = NO
 |																			                         |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)setDispalySettings:(NSString*)displaySettings response:(void (^)(LFWriteAcknowledgeStatus ack, NSError * error))response;


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                                                   |
 set user weight
 Support under Bluetooth connection = YES
 Support under wire connection      = NO
 |																			                         |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */

- (void)setWeight:(double)weight response:(void (^)(LFWriteAcknowledgeStatus ack, NSError * error))response;




/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                                                   |
  Write bookmark information to equipment
  Support under Bluetooth connection = YES
  Support under wire connection      = NO
 |																			                         |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)writeBookMark:(NSString*)bookMark response:(void (^)(LFWriteAcknowledgeStatus ack, NSError * error))response;



#pragma mark - Common login method
/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
  LFopen will choose best way to login with equipment and proceed.
  QRcodestring :  QR code value
  preferredOption : Bluetooth or Internet
  accessToken  : Oauth access token for web access
  accessSecret : Oauth access secret for web access
  pushNotificationToken :  pushnotification token
  headerInfo : additional info to bind with header
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)loginToEquipment:(NSString*)QRcodestring
          preferedMethod:(enum LFQRLoginOption)preferredOption
             accessToken:(NSString*)accessToken
            accessSecret:(NSString*)accessSecret
   pushNotificationToken:(NSString*)pushNotificationToken
              headerInfo:(NSDictionary*)headerInfo
              lfresponse:(void (^)(BOOL success,id responseObject, NSError* error))lfresponse;



#pragma mark - Strength workout support


/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
  Generate Strength equipment Workout from scanned QR code
  QRcodestring :  QR code value
  height : user height, should be in inches
  strengthWorkout : LFQRStrengthWorkout object with tiba value, help vidio url etc
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */

- (void)initiateLFCodeStrengthWorkout:(NSString*)QRcodestring
                               height:(int)height
                             response:(void (^)(LFQRStrengthWorkout * strengthWorkout,NSError* error))response;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
 * allow user to calculate strength workout calorie
 * userWeightInKG : weight of the user in KG
 * durationInSeconds : workout duration in seconds
 * return calorie
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */

- (void)calculateStrengthWorkoutCalories:(enum LFWotkoutIntensityType)intensityType
                          userWeightInKG:(double)userWeight
                       durationInSeconds:(double)duration
                                response:(void (^)(int calorie,NSError* error))response;



/**
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                            |
  Generate Non Connected Cardio equipment Workout from scanned QR code
  Ex - Rower GX
 |																			  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */

- (void)initiateNonConnectedCardioWorkout:(NSString*)QRcodestring
                                 response:(void (^)(LFQRworkout * strengthWorkout,NSError* error))response;



/*
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 |                                                                                            |
  QRcodeString :  QR code value
  workoutResult : LFCardioEquipmentWorkoutResult object which include workout result summary
 |																			                  |
 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 */
- (void)parseLFQRcodeResult:(NSString*)QRcodeString
                             response:(void (^)(LFCardioEquipmentWorkoutResult * workoutResult,NSError* error))response;



// testing method
- (void)writeCommand:(int)command;

// testing method
- (void)sendUserinfo:(NSString*)userXMLstring;
@end
