//
//  LFCardioWorkoutResult.h
//  LFopen
//
//  Created by Dulip Gayan Dasanayaka on 8/5/15.
//  Copyright (c) 2015 Lifefitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFWorkoutResult.h"
#import "LFEquipment.h"
#import "LFShared.h"

@interface LFCardioEquipmentWorkoutResult : LFWorkoutResult

//device
@property   enum  LFEquipmentType equipmentType;
@property   enum  LFEquipmentId equipmentId;
@property   (nonatomic, strong) NSString * equipmentName;
@property   (nonatomic, strong) NSString * bodySerial;

//workout attribute
@property   double averageIncline;
@property   double averageLevel;
@property   double averageMetts;
@property   double averageWatts;
@property   double averageRpm;

@property   double total_movements_count;
@property   double average_candence;  //x per minute
@property   double distance;
@property   double distanceClimbed;
@property   double floorClimbed;
@property   double pace;
@property   double averageSpeed;
@property   double averagePace;
@property   double averageStrideLength;
@property   double averageStraidePerMinute;
@property   (nonatomic)  LFUnitMeasurement   avarageSpeedunit;
@property   (nonatomic)  LFUnitMeasurement   avaragePaceunit;
@property   (nonatomic)  LFUnitMeasurement   distanceUnit;
@property   (nonatomic)  LFUnitMeasurement   distanceClimbedUnit;
@property   (nonatomic)  LFUnitMeasurement   floorClimbedUnit; //Imperial : steps, Metric : Floors

@property   (nonatomic, strong) NSString * workoutResultDetails;
@property   (nonatomic, strong) NSString * guid;

- (NSString*)jsonResult;

@end
