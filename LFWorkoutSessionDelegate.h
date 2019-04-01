//
//  LFWorkoutSessionDelegate.h
//  LFopen
//
//  Created by Dulip Gayan Dasanayaka on 3/12/15.
//  Copyright © 2015 Lifefitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFEquipment.h"
#import "LFWorkoutStream.h"
#import "LFCardioEquipmentWorkoutResult.h"

@protocol LFWorkoutSessionDelegate <NSObject>


///**
// @discussion Inform that LifeFitness Equipment are successfully connected.
// */
- (void)didDeviceConnect;


/**
 @discussion Inform that LifeFitness Equipment are  disconnected.
 */
- (void)didDeviceDisconnect;



/**
 @discussion
 Find Lifefitness equipments which supports bluetooth
 */
- (void)didFindBluetoothSupportEquipments:(NSArray*)lfSupportEquipmentList;



/**
 @discussion Return connected equipment information wrap with LFEquipment Object
 @result equipment: LFEquipment object that include equipmentType, name etc..
 */
- (void)didReceivedEquipmentInfo:(LFEquipment*)equipment;



/**
 @discussion Received the current state of the processing workout.
 This delegate will fire in vevery second while user doing workout on the console
 
 
 @result streamData: LFWorkoutStream object that include calorie,distance,duration etc..
 */
- (void)didReceivedWorkoutStream:(LFWorkoutStream*)streamData;



@optional
/**
 @discussion Connection fail event with error,
 This method will fire for any fail event of the bluetooth connection and cable connection
 */
- (void)didFailConnection:(NSError*)error;



@optional
/**
 @discussion genaral fail event with error,
 This delegate will fire for any fail event, with related error
 */
- (void)didFailWithError:(NSError*)error;



@optional
/**
 @discussion
 This method will fire for any fail event while parsing final result data
 */
- (void)didFailToProcessResultData:(NSError*)error;



@optional
/**
 @discussion Received the final result of the workout
 This delegate will fire after finish the workout by user
 
 
 @result equipmentResult: LFCardioEquipmentWorkoutResult object that include final output of the workout parameter : calorie,distance,duration etc..
 */
- (void)didReceivedResult:(LFCardioEquipmentWorkoutResult*)equipmentResult;



@optional
/**
 @discussion
 This delegate will fire once user start workout with LIfefitness equipment
 */
- (void)didStartWorkout;


@optional
/**
 @discussion
 This delegate will fire once user finished workout with LIfefitness equipment
 */
- (void)didFinishedWorkout;


/**
 @discussion
 This delegate will fire once user paused workout with LIfefitness equipment
 */
- (void)didPauseWorkout;



@optional

// log delegate (will support only in debug versions)
- (void)didWriteLogMessage:(NSString*)log;
- (void)didWriteNotificationLogs:(NSString*)log;
@end
