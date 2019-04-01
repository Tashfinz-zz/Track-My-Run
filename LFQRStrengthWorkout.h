//
//  LFCodeStrengthWorkout.h
//  LFopen
//
//  Created by Dileepa on 8/5/15.
//  Copyright (c) 2015 Lifefitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"
#import "LFQRworkout.h"


@interface LFQRStrengthWorkout : LFQRworkout

@property BOOL isSynergyEquipment;


- (instancetype)initWith:(NSString*)qrString height:(int)height;
- (BOOL)isValidStrengthWorkoutCode;

- (NSArray*)getMusclesWorked;
- (NSArray*)getLabelList;
- (NSArray*)recommendedSettingsBasedOnUserHeight:(double)height;
- (NSArray*)seatPositions;
- (NSArray*)tibaValues;
- (double)weightStackIM;
- (double)weightStackMT;

- (int)calculateCalories:(enum LFWotkoutIntensityType)intensityType userWeightInKG:(double)userWeight durationInSeconds:(double)duration;

@end
