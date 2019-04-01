//
//  LFPresetDataSource.h
//  LFopen
//
//  Created by Dulip Gayan Dasanayaka on 3/12/15.
//  Copyright © 2015 Lifefitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"

@protocol LFPresetDataSource <NSObject>

@optional
/**
 @discussion Equipment is requesting Lifefitness predefine excersice program (Preset), inorder to execute on the equipment.
 Expect preset lists that match for provided equipment type
 
 */
- (NSArray*)didRequestPresetListFor:(enum LFEquipmentId)equipmentId;


/**
 @discussion User has select to start a Preset from the list
 */
- (void)didStartWorkoutPreset:(NSInteger)presetIndex;


/**
 @discussion console request result detail with index
 As a response user has to write result detail to console
 */
- (void)didRequestResultDetailFor:(NSInteger)presetIndex;



/**
 @discussion selected result index on console
 */
- (void)didSelectResultOnConsole:(NSInteger)index;


/**
 @discussion workout has been accepted by user to start
 */
- (void)didAcceptWorkoutPreset;

@end
