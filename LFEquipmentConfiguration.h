//
//  LFconnectConfiguration.h
//  LFopen
//
//  Created by Dulip Gayan Dasanayaka on 30/11/15.
//  Copyright © 2015 Lifefitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"

@interface LFEquipmentConfiguration : NSObject

@property BOOL isResultSummaryReadyToRead;
@property BOOL isSuccessfullyLoggedToConsole;
@property BOOL hasInternetConnection;
@property LFWotkoutSyncStatus syncStatus;
@property LFEquipmentState equipmentState;

@end
