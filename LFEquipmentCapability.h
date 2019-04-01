//
//  LFEquipmentCapability.h
//  LFopen
//
//  Created by Dulip Gayan Dasanayaka on 25/5/15.
//  Copyright (c) 2015 Lifefitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"


@interface LFEquipmentCapability : NSObject

- (instancetype)initWith:(NSString*)qrString;
- (enum LFQRTypes)qrcodeType;
- (BOOL)isBluetoothEnable;
- (BOOL)isInternetEnableInConsole;

@end
