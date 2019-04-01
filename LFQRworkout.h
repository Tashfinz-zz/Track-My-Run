//
//  LFQRworkout.h
//  LFopen
//
//  Created by Dulip Gayan Dasanayaka on 19/5/15.
//  Copyright (c) 2015 Lifefitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"

@interface LFQRworkout : NSObject

@property (nonatomic, strong) NSString *  title;
@property (nonatomic, strong) NSString *  lfCodeValue;


- (instancetype)initWith:(NSString*)qrString;

- (NSArray*)getYouTubeVideoUrls;
- (NSArray*)getS3VideoUrls;
- (NSDictionary*)parseStrengthWorkoutContent:(NSString*)qrCode height:(int)height;
- (NSDictionary*)readLFCodesDetailsFromFileName:(NSString*)fileName;
- (NSArray*)getWorkoutNameList;
- (NSArray*)getS3ThumbnailsImagesUrl;

@end
