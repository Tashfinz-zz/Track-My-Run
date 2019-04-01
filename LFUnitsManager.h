//
//  UnitsManager.h
//  LifeFitness
//
//  Created by xtremelabs on 11-02-09.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"



/**
 * Class containing static methods for converting units between measurements, and formatting units
 */
@interface LFUnitsManager : NSObject {

}

+(NSNumber*)convertNumber:(NSNumber*)number ofType:(LFUnitType)type from:(LFUnitMeasurement)firstMeasurement to:(LFUnitMeasurement)secondMeasurement;

+(NSString*)valueToStringNoUnits:(NSNumber*)number unitType:(LFUnitType)unit unitMeasurement:(LFUnitMeasurement)measurement;
+(NSString*)valueToString:(NSNumber*)number unitType:(LFUnitType)unit unitMeasurement:(LFUnitMeasurement)measurement;

+(NSString*)getUnitName:(LFUnitType)unit unitMeasurement:(LFUnitMeasurement)measurement isAbbreviation:(BOOL)abbreviation;

+(NSString*)timeIntervalToStringWithUnitsEscapeSeconds:(CFTimeInterval)time;
+(NSString*)timeIntervalToString:(CFTimeInterval)seconds;
+(NSString*)timeIntervalToStringWithUnits:(CFTimeInterval)time withUnit:(BOOL)withUnit;
+(double)convertFloorsToSteps:(double)floor;
+(double)convertStepsTofloors:(double)steps;


+(LFUnitMeasurement)unserializeUnit:(NSString*)value;
+(NSString*)serializeUnit:(LFUnitMeasurement)value;
+(NSString*)valueToStringWithPresetUnits:(NSNumber*)number unitValue:(NSString*)unitValue;
+(BOOL) isValidSinceDate:(NSDate*)date;
+(NSString*)getDateString:(NSString*)format date:(NSDate*)date;

@end
