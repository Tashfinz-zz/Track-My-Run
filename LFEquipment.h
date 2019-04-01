//
//  LFEquipment.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 8/10/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"

@interface LFEquipment : NSObject
{

}

@property (nonatomic, retain) NSMutableArray  *cardioProgramList;
@property (nonatomic, retain) NSMutableArray  *cardioIntervalProgramList;

@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *bodySerial;
@property (nonatomic) LFEquipmentId equipmentId;
@property (readonly, assign) LFEquipmentType eqType;
@property BOOL supportStartWorkoutProgram;
@property BOOL supportWorkoutProgramList;
@property BOOL supportWorkoutResultSummary;
@property int protocolVersion;

- (id)initWithEquipmentType:(LFEquipmentType)type;
@end
