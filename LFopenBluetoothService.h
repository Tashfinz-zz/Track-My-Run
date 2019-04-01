//
//  BLELfconnectManager.h
//  CBTutorial
//
//  Created by Dulip Gayan Dasanayaka on 28/4/14.
//  Copyright (c) 2014 Mobiletuts. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LFopen/LFopen.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "LFEquipmentConfiguration.h"


//@protocol DeviceDisconnectionDelegate <NSObject>
//- (void)didBluetoothDisconnected:(LFopenBluetoothService*)bleMgr;
//@end


static const int ERROR_NO_CONSOLE_WITH_PROVIDED_MAC_ADDRESS     = 300;
#define LF_INPUT_BUFFER_SIZE                                      512


@interface LFopenBluetoothService : NSObject <CBCentralManagerDelegate,CBPeripheralDelegate>

@property (strong, nonatomic) CBPeripheral  * discoveredPeripheral;
@property (nonatomic, strong) id<LFWorkoutSessionDelegate> deviceDelegate;
@property (nonatomic, strong) id<LFPresetDataSource> presetDataSource;
@property (nonatomic, strong) id<LFUserInfoDataSource> userInfoDS;
//@property (nonatomic, strong) id<DeviceDisconnectionDelegate> disconnectionDelegate;

//+ (LFopenBluetoothService *)sharedInstance;
- (void)initiateBLEscaning;
- (void)disconnect;
- (BOOL)isDeviceConnected;

- (void)connectToConsoleUsingBLEWithMacAddress:(NSString*)macAddress;
- (void)connectForEquipmentWithName:(NSString*)equipmentname;

// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
// |																			|
#pragma mark - write workout parameter
// |																			|
// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
- (void)writeInclineValue:(double)incline responseStatus:(void (^)(LFWriteAcknowledgeStatus ack , NSError* error))responseStatus;;
- (void)writeWattsValue:(int)watts responseStatus:(void (^)(LFWriteAcknowledgeStatus ack , NSError* error))responseStatus;;
- (void)writeWorkoutLevel:(int)level responseStatus:(void (^)(LFWriteAcknowledgeStatus ack , NSError* error))responseStatus;;
- (void)writeTargetHeartrate:(int)heartrate responseStatus:(void (^)(LFWriteAcknowledgeStatus ack , NSError* error))responseStatus;;
- (void)writeConsoleMessage:(NSString*)message responseStatus:(void (^)(LFWriteAcknowledgeStatus ack , NSError* error))responseStatus;
- (void)writeCurrentHRvalue:(int)hr responseStatus:(void (^)(LFWriteAcknowledgeStatus ack , NSError* error))responseStatus;

// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
// |																			|
#pragma mark - add, start preset
// |																			|
// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
- (void)addPreset:(LFWorkoutPreset*)preset presetIndex:(int)index response:(void (^)(NSError * error))response;
- (void)addPresets:(NSArray*)preset_list  response:(void (^)(NSError * error))response;
- (void)startPreset:(LFWorkoutPreset*)presetname presetIndex:(int)index response:(void (^)(NSError * error))response;
- (void)addResult:(LFCardioEquipmentWorkoutResult*)resultObj index:(int)indexnumber response:(void (^)(NSError * error))response;;
- (void)writePastWorkoutResult:(NSArray*)result_list response:(void (^)(NSError * error))response;
- (void)addResultSummary:(NSString*)resultSummaryJson response:(void (^)(NSError * error))response;;
- (void)writeGPSReplayWorkout:(NSString*)jsonObject  response:(void (^)(NSError * error))response;;


// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
// |																			|
#pragma mark - read from console
// |																			|
// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
- (void)readEquipmentModel:(void (^)(LFWahooEquipmentModel eqmodel,NSError* error))model;
- (void)readEquipmentState:(void (^)(LFEquipmentState eqstate,NSError* error))state;
- (void)readLFEquipmentConfigParameter:(void (^)(LFEquipmentConfiguration * lfconnectParameter ,NSError* error))state;
- (void)readDeviceInfo:(void (^)(LFEquipment * equipmentInfo, NSError* error))response;
- (void)readDetailResult:(void (^)(NSString * detailXmlResult, NSError* error))response;
- (void)readResultSummary:(void (^)(NSString * summaryJson, NSError* error))response;


// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
// |																			|
#pragma mark - Write Excersicer information
// |																			|
// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
- (void)writeDisplayName:(NSString*)displayName response:(void (^)(LFWriteAcknowledgeStatus ack,  NSError* error))response;
- (void)writeAge:(int)age response:(void (^)(LFWriteAcknowledgeStatus ack,  NSError* error))response;
- (void)writeGender:(NSString *)gender response:(void (^)(LFWriteAcknowledgeStatus ack,  NSError* error))response; //m or f
- (void)writeLanguage:(NSString *)language_code response:(void (^)(LFWriteAcknowledgeStatus ack,  NSError* error))response; // en,it,fr
- (void)writeUnit:(LFUnitMeasurement)unit response:(void (^)(LFWriteAcknowledgeStatus ack,  NSError* error))response; // m-metric, i- imperial
- (void)writeDispalySettings:(NSString*)displaySettings response:(void (^)(LFWriteAcknowledgeStatus ack,  NSError* error))response;
- (void)writeWeight:(double)weight response:(void (^)(LFWriteAcknowledgeStatus ack,  NSError* error))response;


// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
// |																			|
#pragma mark - Write Oauth login
// |																			|
// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
- (void)writeOauthLoginInformations:(LFUser*)userObj response:(void (^)(LFWriteAcknowledgeStatus ack,  NSError* error))response;


// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
// |																			|
#pragma mark - Write book mark login
// |																			|
// +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
- (void)writeBookMark:(NSString*)bookMark response:(void (^)(LFWriteAcknowledgeStatus ack,  NSError* error))response;



- (void)writeCommand:(int)command res:(void (^)(BOOL successStatus,NSError* error))response;


#pragma mark whoo workout upload
- (void)writeWahooUserProfile:(LFUser*)userProfile response:(void (^)(NSError * error))response;
- (void)writeWahooWorkout:(LFWorkoutPreset*)preset response:(void (^)(NSError * error))response;


@end
