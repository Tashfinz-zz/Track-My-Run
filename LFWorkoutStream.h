//
//  LFStreamData.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 16/11/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFGPSLocation.h"


struct streamFlags
{
    uint8_t  calorie_format:1;
    uint8_t  distance_format:1;
    uint8_t  distanceClimbed_status:1;
    uint8_t  distanceClimbed_format:1;
    uint8_t  floorClimbed_status:1;
    uint8_t  floorClimbed_format:1;
    uint8_t  RPM_status:1;
    uint8_t  heartrate_status:1;
    uint8_t  incline_status:1;
    uint8_t  watts_status:1;
    uint8_t  level_status:1;
    uint8_t  reserved:5;
};


struct flag0
{
    uint8_t flag1_available:1;
    uint8_t flag2_available:1;
    uint8_t flag3_available:1;
    uint8_t flag4_available:1;
    uint8_t first_notify_packet:1;
    uint8_t final_notify_packet:1;
    uint8_t elapsed_workout_time_available:1;
    uint8_t remain_workout_time_available:1;
};


struct flag1
{
    uint8_t heartrate_available:1;
    uint8_t level_intensity_available:1;
    uint8_t resistance_available:1;
    uint8_t speed_available:1;
    uint8_t candence_available:1;
    uint8_t cumulative_movement_available:1;
    uint8_t cumulative_horizontal_distance_available:1;
    uint8_t cumulative_verticle_distance_available:1;
};


struct flag2
{
    uint8_t verticle_distance_negative_available:1;
    uint8_t cumulative_energy_available:1;
    uint8_t energy_rate_available:1;
    uint8_t mets_available:1;
    uint8_t power_available:1;
    uint8_t torque_available:1;
    uint8_t gear_available:1;
    uint8_t grade_available:1;
};


struct flag3
{
    uint8_t angle_field_available:1;
    uint8_t floor_rate_available:1;
    uint8_t cumulative_floor_available:1;
    uint8_t reserved1:1;
    uint8_t reserved2:1;
    uint8_t reserved3:1;
    uint8_t reserved4:1;
    uint8_t reserved5:1;
};



struct IntValue
{
    unsigned int var:24;
};

enum LFWorkoutState
{
	LFWorkoutStateIdle = 0,
	LFWorkoutStateActive,
	LFWorkoutStatePaused,
	LFWorkoutStateCoolDown,
	LFWorkoutStateSummary,
};

@class LFopenBluetoothService;

@interface LFWorkoutStream : NSObject
{
    
}

@property int streamVersion;
@property int elapsedWorkoutSeconds;
@property int targetWorkoutSeconds;
@property int accumulatedCalories;
@property int targetCalories;
@property double accumulatedDistance;
@property double targetDistance;
@property double accumulatedDistanceClimbedMeter;
@property int targetDistanceClimbedMeter;
@property int currentSpeedRPM;
@property double currentSpeedKM;
@property double targetSpeedKM;
@property double currentIncline;
@property double targetIncline;
@property int targetHeartRate;
@property int currentHeartRate;
@property double currentResistance;
@property int currentLevel;
@property int elapsedHRZone;
@property int targteHRZone;
@property double accumilatedFloorClimbed;
@property int targetFloorClimbed;
@property double currentCadence;
@property double currentMets;
@property enum LFWorkoutState workoutState;
@property (nonatomic, retain) LFGPSLocation * matchGPSLocation;

- (id)initWithLFopneOneData:(NSData *)data deviceType:(int)deviceType blemanager:(LFopenBluetoothService*)bleManager;
- (id)initWithWhahooFitnessData:(NSData *)data;
- (double)getCompletedPercentage;
- (NSInteger)getTargetParameter;
- (void)updateValues:(NSData*)packetData;
@end
