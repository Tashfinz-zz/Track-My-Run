//
//  WorkoutEntity.h
//  LFOpenDemo
//
//  Created by Dileepa on 5/11/14.
//  Copyright (c) 2014 Dileepa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"
#import "LFUnitsManager.h"


@interface LFPresetWorkoutParam : NSObject
{
    enum LFWorkoutParams type;
    NSString * name;
    NSString * str_unit;
    double value;
}
@property enum LFWorkoutParams type;
@property (nonatomic, strong) NSString * name;
@property (nonatomic, assign) double value;
@property (nonatomic, strong) NSString * str_unit;
@end


@interface LFSegmentParam : NSCoder
{
    enum SegmentType type;
    double duration;
    double speed;
    double level;
    double heartRate;
    double incline;
}
@property enum SegmentType type;
@property (nonatomic, assign) double duration,speed,level,heartRate,incline;

- (instancetype)initWithParams:(enum SegmentType)tp duration:(double)du speed:(double)sp  heartRate:(double)hr level:(double)lvl incline:(double)inc;

@end


@interface LFPresetGoal : NSObject
{
    enum GoalTypes goalType;
    enum LFWorkoutParams goal_parameter_type;
    enum LFEquipmentType eqType;
    enum CardioProgramType woType;
    enum SegmentType segmentType;
    LFUnitMeasurement goal_unit;
    NSString * goalName;
    NSArray * supportedEquipments;
    NSMutableArray * workoutParameters;
    NSMutableArray * userParameters;
    NSMutableArray * segmentDataList;

    
}


@property enum GoalTypes goalType;
@property enum LFWorkoutParams goal_parameter_type;
@property enum LFEquipmentType eqType;
@property enum CardioProgramType woType;
@property enum SegmentType segmentType;
@property LFUnitMeasurement goal_unit;
@property (nonatomic, strong) NSString * goalName;
@property (nonatomic, strong) NSArray * supportedEquipments;
@property (nonatomic, strong) NSMutableArray * workoutParameters,* userParameters;
@property (nonatomic, strong) NSMutableArray * segmentDataList, *segmentTimeList, *segmentDataList2;

@end

@interface LFCardioProgram : NSObject
{
    NSString *workoutName;
    NSMutableArray *goalList;
    enum CardioProgramType type;
}

@property (nonatomic, strong) NSString *workoutName;
@property (nonatomic, strong) NSMutableArray *goalList;
@property enum CardioProgramType type;

@end




@interface LFWorkoutPreset : NSObject

@property (nonatomic, strong) LFPresetWorkoutParam * goalParameter;
@property (nonatomic, strong) LFPresetGoal *presetGoal;
@property (nonatomic, strong) NSString * presetName;
@property (nonatomic, strong) NSString * presetFile;
@property (nonatomic) enum LFPresetType presetType;
@property  LFUnitMeasurement unit;
@property (nonatomic, strong) NSArray * listOfGPSpoint;
@property (nonatomic, strong) NSArray * listOfDeviceType;



/*
 
 Initialize
 
 */
- (instancetype)initWithPresetType:(enum LFPresetType)type preset:(NSString*)presetXmlFile;


/*
 
 Build preset for given GPS workout result, So equipment can simulate GSP workout
 
 */
- (NSString*)createPresetFileForGPSWorkout;


@end



@interface LFActivityInfo : NSObject
{
    long userId;
    long workoutId;
    long workoutActivityId;
    long activityDefinitionId;
}

@property (nonatomic) long userId;
@property (nonatomic) long workoutId;
@property (nonatomic) long workoutActivityId;
@property (nonatomic) long activityDefinitionId;

@end

