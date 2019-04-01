//
//  WorkoutDataManager.h
//  LFopen
//
//  Created by Dileepa on 11/11/14.
//  Copyright (c) 2014 Lifefitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFWorkoutEntity.h"
#import "LFWorkout.h"
#import "LFUser.h"



@interface LFEquipmentWorkoutBuilder : NSObject



+ (LFEquipmentWorkoutBuilder*)getSharedInstance;

/*
 * get LF equipment list
 */
- (NSMutableArray *)getEquipmentList;
- (NSMutableArray *)getPresetsForEquipment:(int)eqId;
- (LFWorkoutPreset*)getWorkOutFor:(LFPresetGoal*)selectedGoal;
- (LFWorkoutPreset*)getWorkOutFor:(LFPresetGoal*)selectedGoal withUser:(LFUser*)user;
- (LFWorkoutPreset*)getWorkOutFor:(LFPresetGoal*)selectedGoal withUser:(LFUser*)user forActivity:(LFActivityInfo*)activitInfo;

/*
 * get LFEquipment by equipment type
 */

- (LFEquipment*)getEquipment:(int)equipmentType;


/*
 * get LFCardioProgram by program type and selected equipment
 */

- (LFCardioProgram*)getCardioProgram:(int)programType forEquipment:(LFEquipment*)equipment;


/*
 * get LFPresetGoal by goalType and selected LFCardioProgram
 */
- (LFPresetGoal*)getPresetGoal:(int)goalType forCardioProgram:(LFCardioProgram *)program;


/*
 * get LFWorkout for LFPresetGoal
 */
- (NSMutableArray *)getPresetsForEquipment:(int)eqId user:(LFUser *)user;

/*
 * get LFPresetGoal by segmentType and selected LFCardioProgram
 */
-(LFPresetGoal*) getIntervalPresetGoal:(int)segmentType forCardioProgram:(LFCardioProgram *)program;

@end
