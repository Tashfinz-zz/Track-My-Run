//
//  LFWorkoutResult.h
//  LFopen
//
//  Created by Dulip Gayan Dasanayaka on 8/5/15.
//  Copyright (c) 2015 Lifefitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"

@interface LFWorkoutResult : NSObject

@property (nonatomic)                   long long           resultId;
@property (nonatomic, copy)				NSString*           workoutName;
@property (nonatomic, copy)				NSString*           description;
@property (nonatomic, copy)				NSDate*             performDate;
@property (nonatomic)                   int                 calories;
@property (nonatomic)                   double              duration;
@property (nonatomic)                   LFUnitMeasurement   unit;
@property (nonatomic)                   double              heartRate;

@end
