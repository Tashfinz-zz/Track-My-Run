//
//  LFConstant.h
//  LFDeviceLib
//
//  Created by Dulip Gayan Dasanayaka on 11/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LF_INPUT_BUFFER_SIZE                 512
#define BUILD_FOR_OUTSIDE_DEVELOPER          0

#define STRING_TRUE                  @"true"
#define STRING_FALSE                 @"false"




extern NSInteger const   kLFInvalidQRcode;
extern NSInteger const   kLFMACAddressNotFound;
extern NSInteger const   kLFIncompleteQRCode;
extern NSInteger const   kLFConsoleDoesNotHaveInternetConnection;
extern NSInteger const   kLFAssertOffline;
extern NSInteger const   kLFInvalidAPNToken;
extern NSInteger const   kLFFailToParseEquipmentWorkoutResult;
extern NSInteger const   kLFUnknownError;
extern NSInteger const   kLFCodeVideoNotAvailable;
extern NSInteger const   kLFNoDataForSelectedQRStrengthWorkout;
extern NSInteger const   kLFFailLicenseValidation;
extern NSInteger const   kLFCanNotFindLFopenLicense;
extern NSInteger const   kLFFailToLoginWithBluetooth;
extern NSInteger const   kLFFailToLoginWithPushnotification;
extern NSInteger const   kLFQRLoginFail;
extern NSInteger const   kLFInvalidAuthData;
extern NSInteger const   kLFNoConnectedEquipment;
extern NSInteger const   kLFNoConnectedEquipment;
extern NSInteger const   kLFServiceNotSupported;
extern NSInteger const   kLFInvalidParameter;
extern NSInteger const   kLFInvalidInputData;


// writing parameter
extern NSInteger const   kLFfailToWriteIncline;
extern NSInteger const   kLFfailToWriteWatts;
extern NSInteger const   kLFfailToWriteHeartRate ;
extern NSInteger const   kLFfailToWriteConsoleMessage;
extern NSInteger const   kLFfailToWriteLevel;
extern NSInteger const   kLFInclineValueIntervalPeriod;
extern NSInteger const   kLFExceedMaxUserNameLength;
extern NSInteger const   kLFInvalidCheckSum;
extern NSInteger const   kLFEquipmentBusy;
extern NSInteger const   kLFUnsuportedUploadItem;
extern NSInteger const   kLFUnsuportedUploadItemFormat;
extern NSInteger const   kLFUploadNotPermited;
extern NSInteger const   kLFNOUploadInProgress;
extern NSInteger const   kLFUploadfail;
extern NSInteger const   kLFWahooErrorUploadFaliureSizeExceed;
extern NSInteger const   kLFWahooErrorUploadCompleteDataSizeMismatch;
extern NSInteger const   kLFWahooErrorUploadFaliureAtLeastOnePacketIsMissing;
extern NSInteger const   kLFWahooErrorUploadFaliureDueToInactivityTimeout;
extern NSInteger const   kLFWahooErrorUploadFaliureDueToUploadTimeout;
extern NSInteger const   kLFWahooErrorUploadFaliureDueCRCMismatch;
extern NSInteger const   kLFWhooControlUploadUploadDataSizeMismatch;
extern NSInteger const   kLFUploadCancelByUser;
extern NSInteger const   kLFUploadSuccessButInvalidItem ;
extern NSInteger const   kLFUploadSuccessButUnsuportedItem ;
extern NSInteger const   kLFUploadSuccessButUnknownFailure;
extern NSInteger const   kLFInvalidInputData;


extern NSString * const  kLFInvalidQRcodeString;
extern NSString * const  kLFNoMACAddressString;
extern NSString * const  kLFIncompleteQRCodeString;
extern NSString * const  kLFConsoleDoesNotHaveInternetConnectionString;
extern NSString * const  kLFAssertOfflineString;
extern NSString * const  kLFInvalidAPNTokenString;
extern NSString * const  kLFUnknownErrorString;
extern NSString * const  kLFCodeVideoNotAvailableString;
extern NSString * const  kLFNoDataForSelectedQRStrengthWorkoutString;
extern NSString * const  kLFFailLicenseValidationString;
extern NSString * const  kLFCanNotFindLFopenLicenseString;
extern NSString * const  kLFFailToParseEquipmentWorkoutResultString;
extern NSString * const  kLFFailToLoginWithBluetoothString;
extern NSString * const  kLFFailToLoginWithPushnotificationString;
extern NSString * const  kLFQRLoginFailString;
extern NSString * const  kLFInvalidAuthDataString;
extern NSString * const  kLFNoConnectedEquipmentString;
extern NSString * const  kLFServiceNotSupportedString;
extern NSString * const  kLFInvalidParameterString;
extern NSString * const  kLFInvalidInputDataString;



// writing parameter
extern NSString * const  kLFfailToWriteInclineString;
extern NSString * const  kLFfailToWriteWattsString;
extern NSString * const  kLFfailToWriteHeartRateString;
extern NSString * const  kLFfailToWriteConsoleMessageString;
extern NSString * const  kLFfailToWriteLevelString;
extern NSString * const  kLFInclineValueIntervalPeriodString;
extern NSString * const  kLFExceedMaxUserNameLengthString;
extern NSString * const  kLFInvalidCheckSumString;
extern NSString * const   kLFEquipmentBusyString;
extern NSString * const   kLFUploadfailString;
extern NSString * const   kLFUploadSuccessButInvalidItemString ;
extern NSString * const   kLFUploadSuccessButUnsuportedItemString ;
extern NSString * const   kLFUploadSuccessButUnknownFailureString;


extern NSString * const   kLFWahooErrorUnsupportedUploadItem ;
extern NSString * const   kLFWahooErrorUnsupportedUploadItemFormat;
extern NSString * const   kLFWahooErrorUnsupportedUploadIsNotPermitter;
extern NSString * const   kLFWahooErrorNoUploadProgress;
extern NSString * const   kLFWahooErrorUploadfaliureSizeExceedString;
extern NSString * const   kLFWahooErrorUploadfaliureInactive;
extern NSString * const   kLFWahooErrorUploadfaliureDuetoUpload;
extern NSString * const   kLFWahooErrorUploadfaliureDuetoItemMismatch;
extern NSString * const   kLFWahooErrorUserCancelUpload;
extern NSString * const   kLFWahooErrorUploadCompleteDataSizeMismatchString;
extern NSString * const   kLFWahooErrorUploadCompleteCRCMismatchString;
extern NSString * const   kLFWahooErrorUploadCompleteButTimeoutProcessing;
extern NSString * const   kLFWahooErrorUploadFaliureAtLeastOnePacketIsMissingString;
extern NSString * const   kLFWahooErrorUploadFaliureDueToInactivityTimeoutString;
extern NSString * const   kLFWahooErrorUploadFaliureDueToUploadTimeoutString;

//bluetooth
extern NSString * const  kLFNoConnectedEquipmentString;
extern NSString * const  kLFServiceNotSupportedString;
extern NSString * const  kLFInvalidInputDataString;

/**
 Preferred Language code of the Virtual Trainer user. Possible values: 'en_US', 'en', 'de', 'es', 'fr', 'it', 'ja', 'nl', 'pt', 'ru', 'tr', 'zh'
 */
typedef enum LFLanguageCode
{
    LFLangCode_EN_US = 0,
    LFLangCode_EN,
    LFLangCode_DE,
    LFLangCode_ES,
    LFLangCode_FR,
    LFLangCode_IT,
    LFLangCode_JA,
    LFLangCode_NL,
    LFLangCode_PT,
    LFLangCode_RU,
    LFLangCode_TR,
    LFLangCode_ZH,
    
}LFLanguageCode;


typedef enum {
    LFUserGenderFemale,
    LFUserGenderMale,
    LFUserGenderNone = -1
} LFUserGender;


typedef enum {
    LFUnitMeasurementImperial,
    LFUnitMeasurementMetric,
    LFUnitMeasurementNone
} LFUnitMeasurement;


typedef enum {
    LFUnitTypeHeight,
    LFUnitTypeDistance,
    LFUnitTypeWeight,
    LFUnitTypeSpeed,
    LFUnitTypePace,
    LFUnitTypeCalories,
    LFUnitTypeTime,
    LFUnitTypeRepetition,
    LFUnitTypeDistanceClimed,
    LFUnitTypeFloorClimbed,
    LFUnitTypeHartRate,
    LFUnitTypeWaistLine,
    LFUnitTypeFlexibility,
    LFUnitTypeStrength,
    LFUnitTypeBMI
} LFUnitType;


typedef enum : NSUInteger {
    LFWahooEquipmentModelUnknown = 0,
    LFWahooEquipmentModelTreadmill = 1,
    LFWahooEquipmentModelBike = 2,
    LFWahooEquipmentModelStepper = 3,
    LFWahooEquipmentModelStepMill = 4,
    LFWahooEquipmentModelCrossTrainer = 5,
    LFWahooEquipmentModelTotalBodyTrainer = 6,
    LFWahooEquipmentModelTreadClimber = 7,
    LFWahooEquipmentModelRower = 8,
    LFWahooEquipmentRecumbentBike = 144,
} LFWahooEquipmentModel;


typedef enum : NSUInteger {
    LFEquipmentStateUnknown = 0,
    LFEquipmentStateIdel = 1,
    LFEquipmentStatePaused = 2,
    LFEquipmentStateinUse = 10,
    LFEquipmentStateinUseAfterUpload = 33,
    LFEquipmentStateFinished = 128
} LFEquipmentState;


typedef enum : NSUInteger {
    LFWriteAcknowledgeStatusSuccess = 1,
    LFWriteAcknowledgeStatusInvalidinput = 2,
    LFWriteAcknowledgeStatusWritingFail = 3,
    LFWriteAcknowledgeStatusUnexpectedError = 3,
} LFWriteAcknowledgeStatus;


typedef enum LFWotkoutSyncStatus {
    LFWotkoutSyncStatusNone  =  0,
    LFWotkoutSyncStatusWillSync = 1,
    LFWotkoutSyncStatusWillnotSync = 2,
    LFWotkoutSyncStatusSyncSuccessfully = 3,
    LFWotkoutSyncStatusSyncFail = 4
}LFWotkoutSyncStatus;


/*
 
 01 = CSAFE Card (see CID 3 or 4)
 02 = LED Bikes
 03 = LED Stepper
 04 = LED Treadmills
 05 = LED Cross-Trainers: Front Drive
 06 = LED Cross-Trainers: Rear Drive
 10 = LED Summit Trainer
 12 = Integrated LCD Bikes (12”)
 13 = Integrated LCD Stepper (12”)
 14 = Integrated LCD Treadmills (12”)
 16 = Integrated LCD Cross-Trainers (12”)
 17 = Integrated LCD Adjustable Cross-Trainer (12”)
 18 = Integrated LCD consumer T9e Treadmill (12”)
 19 = Sports_Tread (consumer w/ USB – 2010)
 20 = Integrated LCD Summit Trainer (12”)
 21 = LED Achieve Consoled Treadmill (95Ta)
 22 = 7” LCD Inspire Console - Treadmill (95Ti)
 23 = 15” LCD Engage Console - Treadmill (95Te)
 24 = LED Achieve Console - Cross Trainer (95Xa)
 25 = 7” LCD Inspire Console - Cross Trainer (95Xi)
 26 = 15” LCD Engage Console - Cross Trainer (95Xe)
 27 = LED Achieve Console - Upright Bike (95Ca)
 28 = 7” LCD Inspire Console - Upright Bike (95Ci)
 29 = 15” LCD Engage Console - Upright Bike (95Ce)
 30 = LED Achieve Console - Recumbent Bike (95Ra)
 31 = 7” LCD Inspire Console - Recumbent Bike (95Ri)
 32 = 15” LCD Engage Console - Recumbent Bike (95Re)
 33 = LED Achieve Console – Platform (95Pa)
 34 = 7” LCD Inspire Console – Platform (95Pi)
 35 = 15” LCD Engage Console – Platform (95Pe)
 36 = NDT Achieve Console - Treadmill (95T?)
 37 = NDT Achieve Console - Cross Trainer (95X?)
 38 = NDT Achieve Console - Upright Bike (95C?)
 39 = NDT Achieve Console - Recumbent Bike (95R?)
 40 = NDT Achieve Console - Platform (95P?)
 41 = Integrity Treadmill – Classic Refresh (LED & LCD)
 42 = Integrity Bike – Classic Refresh (LED & LCD)
 43 = Integrity Cross-Trainer – Classic Refresh (LED & LCD)
 44 = Integrity Step – Classic Refresh (LED & LCD)
 45 = Integrity Summit-Trainer – Classic Refresh (LED & LCD)
 46 = Activate Treadmill – (Optima/midline LED)
 47 = Activate Bike – (Optima/midline LED)
 48 = Activate Cross-Trainer – (Optima/midline LED)
 
 49 = Discover Treadmill Engage (LCD)
 50 = Discover Cross Trainer Engage (LCD)
 51 = Discover Upright Bike Engage(LCD)
 52 = Discover Recumbent Bike Engage(LCD)
 53 = Discover Treadmill Inspire (LCD)
 54 = Discover Cross Trainer Inspire (LCD)
 55 = Discover Upright Bike Inspire (LCD)
 56 = Discover Recumbent Bike Inspire (LCD)
 57 = Discover FlexStrider Engage (LCD)
 58 = Discover FlexStrider Inspire (LCD)
 59 = Achieve FlexStrider (Zeus/Achieve Refresh, 8”)
 60 = Discover PowerMill Engage (LCD)
 61 = Discover PowerMill Inspire (LCD)
 62 = Integrity PowerMill (LED)
 63 = Explore PowerMill (Zeus/Achieve Refresh, 8”, Aug 2013)
 64 = Explore Treadmill (Zeus/Achieve Refresh, 8”, Aug 2013)
 65 = Explore Cross Trainer (Zeus/Achieve Refresh, 8”, Aug 2013)
 66 = Explore Upright Bike (Zeus/Achieve Refresh, 8”, Aug 2013)
 67 = Explore Recumbent Bike (Zeus/Achieve Refresh, 8”, Aug 2013)
 68 = Aquaman Treadmill Engage (LCD)
 69 = Aquaman Cross Trainer Engage (LCD)
 70 = Aquaman Upright Bike Engage(LCD)
 71 = Aquaman Recumbent Bike Engage(LCD)
 72 = Aquaman FlexStrider Engage (LCD)
 73 = Aquaman PowerMill Engage (LCD)
 74 = Cross-Trainer Rear Entry - Fixed Stride Base (FS4/Munchkin/V3, ECB base)
 75 = Cross-Trainer Rear Entry - Adjustable Stride Base (FS6/Munchkin/V5, ECB base)
 76 = Cross-Trainer Side-Entry base (Hercules, RCB base)
 77 = Upright Bike Base (Hercules, RCB base)
 78 = Recumbent Bike Base (Hercules, RCB base)
 79 = Tread - Simple Base (10% base, Hercules, SIB base)
 80 = Tread - Featured Base (15% base, Hercules, SIB base)
 81 = FlexStrider (Hercules, RCB base)
 82 = Powermill (Hercules, SIB base)
 
 89 = Superman Cross Trainer
 90 = Superman Upright Bike
 91 = Superman Recumbent Bike
 92 = Superman FlexStrider
 93 = Superman Arc Trainer
 94 = Superman Treadmill
 95 = Superman PowerMill\
\
\\\
 
 
 96 = T3 Upright Bike
 97 = T3 Recumbent Bike
 98 = T3 Arc Trainer
 99 = T3 Treadmill
 
  88 = Arc Trainer (Hercules - T2)


*/

/*
 
 74 = Cross-Trainer Rear Entry - Fixed Stride Base (Hercules, Munchkin, FS4/V3, ECB base)
 75 = Cross-Trainer Rear Entry - Adjustable Stride Base (Hercules, Munchkin, FS6/V5, ECB base)
 76 = Cross-Trainer Side-Entry base (Hercules, RCB base)
 77 = Upright Bike Base (Hercules, RCB base)
 78 = Recumbent Bike Base (Hercules, RCB base)
 79 = Tread - Simple Base (Hercules, 10% base, SIB base)
 80 = Tread - Featured Base (Hercules, 15% base, SIB base)
 81 = FlexStrider (Hercules, RCB base)
 82 = Powermill (Hercules, SIB base)
 83 = Arc Trainer (Aquaman, Falabella)
 84 = Upright Bike - no message center (Duplo, RCB base)
 85 = Recumbent Bike - no message center (Duplo, RCB base)
 86 = Tread - no message center (Duplo, SIB base)
 87 = FlexStrider - no message center (Duplo, RCB base)
 88 = Arc Trainer (Hercules - T2)
 
 
 103 = Upright Bike - no message center (T1, Cybex version of the Duplo console, RCB base)
 104 = Recumbent Bike - no message center (T1, Cybex version of the Duplo console, RCB base)
 105 = Tread - no message center (T1, Cybex version of the Duplo console, SIB-MDB base)
 106 = Cross-Trainer - no message center (T1, Cybex version of the Duplo console, RCB base)
 107 = Arc - no message center (T1, Cybex version of the Duplo console, RCB base)
 
 */

/* Update 27th September 2017
 
 110 = Bluth Treadmill - Integrity D (Featured) base
 111 = Bluth Cross Trainer - Integrity D (Featured) base
 112 = Bluth Upright Bike - Integrity D (Featured) base
 113 = Bluth Recumbent Bike - Integrity D (Featured) base
 114 = Bluth Power Mill - Integrity D (Featured) base
 115 = Bluth Arc Trainer - Integrity D (Featured) base
 116 = Bluth FlexStrider - Integrity D (Featured) base
 121 = Bluth Treadmill - Integrity S (Simple) base
 122 = Bluth Cross Trainer - Integrity S (Simple) base
 123 = Bluth Upright Bike - Integrity S (Simple) base
 124 = Bluth Recumbent Bike - Integrity S (Simple) base
 125 = Bluth Power Mill - Integrity S (Simple) base
 126 = Bluth Arc Trainer - Integrity S (Simple) base
 127 = Bluth FlexStrider - Integrity S (Simple) base
 128 = Bluth Treadmill - Elevation base
 129 = Bluth Cross Trainer - Elevation base
 130 = Bluth Upright Bike - Elevation base
 131 = Bluth Recumbent Bike - Elevation base
 132 = Bluth Power Mill - Elevation base
 133 = Bluth Arc Trainer - Elevation base
 134 = Bluth FlexStrider - Elevation base
 
 */

/* Update 20th November 2017
 
 108 = Powermill - no message center (T1, Cybex version of the Duplo console, SIB-MDB base)
 109 = Powermill - no message center (Duplo, SIB-MDB base)
 110 = Bluth Treadmill
 111 = Bluth Cross Trainer
 112 = Bluth Upright Bike
 113 = Bluth Recumbent Bike
 114 = Bluth Power Mill
 115 = Bluth Arc Trainer
 
 */


typedef enum LFEquipmentType
{
    LFEquipmentType_Unknown                                 =           -1,
    
    LFEquipmentType_Treadmill_Classic_Refresh               =           41,
    LFEquipmentType_Bike_Classic_Refresh                    =           42,
    LFEquipmentType_Crosstrainer_Classic_Refresh            =           43,
    LFEquipmentType_Step_Classic_Refresh                    =           44,
    LFEquipmentType_Steper                                  =           3,
    LFEquipmentType_Summittrainer_Classic_Refresh           =           45,
    LFEquipmentType_LED_Summit_Trainer                      =           10,
    LFEquipmentType_Integrated_LCD_Stepper                  =           13,
    LFEquipmentType_Integrated_LCD_Summit_Trainer           =           20,
    
    LFEquipmentType_Treadmill_Led                           =            4,
    LFEquipmentType_Treadmill_Lcd                           =           14,
    LFEquipmentType_Treadmill_Lcd_Con                       =           18,
    LFEquipmentType_Treadmill_Acheive                       =           21,
    LFEquipmentType_Treadmill_Inspire                       =           22,
    LFEquipmentType_Treadmill_Engage                        =           23,
    LFEquipmentType_Treadmill_1_1                           =            1,
    LFEquipmentType_Treadmill_Discover_Engage               =           49,
    LFEquipmentType_Treadmill_Discover_Inspire              =           53,
    LFEquipmentType_Treadmill_Explore                       =           64,
    LFEquipmentType_Treadmill_Aquaman                       =           68,
    LFEquipmentType_Treadmill_Archive                       =           64,
    LFEquipmentType_Treadmill_NDT_Achieve_Console           =           36,
    LFEquipmentType_Treadmill_Activate                      =           46,
    LFEquipmentType_Treadmill_Hercules_Simple               =           79,
    LFEquipmentType_Treadmill_Hercules_Feature              =           80,
    LFEquipmentType_Treadmill_Superman                      =           94,
    LFEquipmentType_Treadmill_Duplo                         =           86,
    LFEquipmentType_Treadmill_T3                            =           99,
    LFEquipmentType_Treadmill_T1                            =           105,


    LFEquipmentType_Crosstrainer_Fd_Led                     =            5,
    LFEquipmentType_Crosstrainer_Rd_Led                     =            6,
    LFEquipmentType_Crosstrainer_Lcd                        =           16,
    LFEquipmentType_Crosstrainer_Lcd_Adj                    =           17,
    LFEquipmentType_Crosstrainer_Acheive                    =           24,
    LFEquipmentType_Crosstrainer_Inspire                    =           25,
    LFEquipmentType_Crosstrainer_Engage                     =           26,
    LFEquipmentType_Crosstrainer_1_1                        =            2,
    LFEquipmentType_Crosstrainer_Discover_Engage            =           50,
    LFEquipmentType_Crosstrainer_Discover_Inspire           =           54,
    LFEquipmentType_Crosstrainer_Archive                    =           65,
    LFEquipmentType_Crosstrainer_Aquaman                    =           69,
    LFEquipmentType_Crosstrainer_NDT_Achieve_Console        =           37,
    LFEquipmentType_CrossTrainer_ActivateCross              =           48,
    LFEquipmentType_CrossTrainer_Rear_Fixed_Stride          =           74,
    LFEquipmentType_CrossTrainer_Rear_Adjustable_Stride     =           75,
    LFEquipmentType_CrossTrainer_Rear_Side_Entry            =           76,
    LFEquipmentType_CrossTrainer_Superman                   =           89,
    LFEquipmentType_CrossTrainer_Duplo                      =           87,
    LFEquipmentType_CrossTrainer_T1                         =           106,

    
    LFEquipmentType_UprightBike_Led                         =           11,
    LFEquipmentType_UprightBike_Acheive                     =           27,
    LFEquipmentType_UprightBike_Inspire                     =           28,
    LFEquipmentType_UprightBike_Engage                      =           29,
    LFEquipmentType_UprightBike_Discover_Engage             =           51,
    LFEquipmentType_UprightBike_Discover_Inspire            =           55,
    LFEquipmentType_Bike_1_1                                =            0,
    LFEquipmentType_UprightBike_Archive                     =           66,
    LFEquipmentType_UprightBike_Aquaman                     =           70,
    LFEquipmentType_UprightBike_NDT_Achieve_Console         =           38,
    LEEquipmentType_Bike_Activate                           =           47,
    LFEquipmentType_Upright_Bike_Hercules                   =           77,
    LFEquipmentType_Upright_Bike_Superman                   =           90,
    LFEquipmentType_Upright_Bike_Duplo                      =           84,
    LFEquipmentType_Upright_Bike_T3                         =           96,
    LFEquipmentType_Upright_Bike_T1                         =           103,
    
    
    
    LFEquipmentType_RecumbentBike_Led                       =           12,
    LFEquipmentType_RecumbentBike_Acheive                   =           30,
    LFEquipmentType_RecumbentBike_Inspire                   =           31,
    LFEquipmentType_RecumbentBike_Engage                    =           32,
    LFEquipmentType_RecumbentBike_Discover_Engage           =           52,
    LFEquipmentType_RecumbentBike_Discover_Inspire          =           56,
    LFEquipmentType_RecumbentBike_Discover_Archive          =           67,
    LFEquipmentType_RecumbentBike_Aquaman                   =           71,
    LFEquipmentType_RecumbentBike_NDT_Achieve_Console       =           39,
    LFEquipmentType_RecumbentBike_Hercules                  =           78,
    LFEquipmentType_RecumbentBike_Superman                  =           91,
    LFEquipmentType_RecumbentBike_Duplo                     =           85,
    LFEquipmentType_RecumbentBike_T3                        =           97,
    LFEquipmentType_RecumbentBike_T1                        =          104,

    
    LFEquipmentType_Consumer_Treadmill                      =           19,
    LFEquipmentType_Consumer_Crosstrainer                   =          260,
    LFEquipmentType_Consumer_Lifecycle                      =          261,
    LFEquipmentType_Consumer_Treadmill_T3                   =          262,
    LFEquipmentType_Consumer_Smart_Crosstrainer             =          263,
    LFEquipmentType_Consumer_Smart_Lifecycle                =          264,
    LFEquipmentType_Consumer_Treadmill_F3                   =          265,
    LFEquipmentType_Consumer_Treadmill_T5                   =          266,
    LFEquipmentType_Consumer_Treadmill_TrackConnect         =          269,
    LFEquipmentType_Consumer_UprightBike_TrackConnect       =          270,
    LFEquipmentType_Consumer_CrossTrainer_TrackConnect      =          271,
    LFEquipmentType_Consumer_SummitTrainer_TrackConnect     =          272,
    LFEquipmentType_Consumer_Rower_TrackConnect             =          273,
    LFEquipmentType_Consumer_Recumbent_TrackConnect         =          267,
    LFEquipmentType_Consumer_Smart_Recumbent                =          268,
    
    LFEquipmentType_Discover_FlexStrider_Engage             =          57,
    LFEquipmentType_Discover_FlexStrider_Inspire            =          58,
    LFEquipmentType_Discover_Achieve_FlexStrider            =          59,
    LFEquipmentType_Aquaman_FlexStrider                     =          72,
    LFEquipmentType_FlexStrider_Hercules                    =          81,
    LFEquipmentType_FlexStrider_Superman                    =          92,
    
    LFEquipmentType_Discover_PowerMill_Engage               =          60,
    LFEquipmentType_Discover_PowerMill_Inspire              =          61,
    LFEquipmentType_Integrity_PowerMill                     =          62,
    LFEquipmentType_Achieve_PowerMill                       =          63,
    LFEquipmentType_Aquaman_PowerMill                       =          73,
    LFEquipmentType_PowerMill_Hercules                      =          82,
    LFEquipmentType_PowerMill_Superman                      =          95,
    
    LFEquipmentType_Falabella                               =          83,
    LFEquipmentType_ArcTrainer_Superman                     =          93,
    LFEquipmentType_ArcTrainer_Hercules                     =          88,
    LFEquipmentType_ArcTrainer_T3                           =          98,
    LFEquipmentType_ArcTrainer_T1                           =          107,
    
    LFEquipmentType_Bluth_Treadmill_Integrity_D             =           110,
    LFEquipmentType_Bluth_Cross_Trainer_Integrity_D         =           111,
    LFEquipmentType_Bluth_Upright_Bike_Integrity_D          =           112,
    LFEquipmentType_Bluth_Recumbent_Bike_Integrity_D        =           113,
    LFEquipmentType_Bluth_Power_Mill_Integrity_D            =           114,
    LFEquipmentType_Bluth_Arc_Trainer_Integrity_D           =           115,
    LFEquipmentType_Bluth_FlexStrider_Integrity_D           =           116,
    
    LFEquipmentType_Mulder_Treadmill                        =           117,
    LFEquipmentType_Mulder_Upright_Bike                     =           118,
    LFEquipmentType_Mulder_Recumbent_Bike                   =           119,
    LFEquipmentType_Mulder_Arc_Trainer                      =           120,
    
    LFEquipmentType_Bluth_Treadmill_Integrity_S             =           121,
    LFEquipmentType_Bluth_Cross_Trainer_Integrity_S         =           122,
    LFEquipmentType_Bluth_Upright_Bike_Integrity_S          =           123,
    LFEquipmentType_Bluth_Recumbent_Bike_Integrity_S        =           124,
    LFEquipmentType_Bluth_Power_Mill_Integrity_S            =           125,
    LFEquipmentType_Bluth_Arc_Trainer_Integrity_S           =           126,
    LFEquipmentType_Bluth_FlexStrider_Integrity_S           =           127,
    
    LFEqupimentType_Bluth_Treadmill_Elevation_Base          =           128,
    LFEqupimentType_Bluth_Cross_Trainer_Elevation_Base      =           129,
    LFEqupimentType_Bluth_Upright_Bike_Elevation_Base       =           130,
    LFEqupimentType_Bluth_Recumbent_Bike_Elevation_Base     =           131,
    LFEqupimentType_Bluth_Power_Mill_Elevation_Base         =           132,
    LFEqupimentType_Bluth_Arc_Trainer_Elevation_Base        =           133,
    LFEqupimentType_Bluth_FlexStrider_Elevation_Base        =           134

    
}LFEquipmentType;

/*
   260 = Consumer cross trainer  261 = Consumer upright bike  262 = T3 Consumer treadmill  263 = Smart cross trainer  264 = Smart upright bike  265 = F3 Consumer Treadmill  266 = T5 Consumer Treadmill  267 = Consumer recumbent bike  268 = Smart recumbent bike
 */

typedef enum  LFEquipmentId {
    LFEQUIPMENT_ID_TREADMILL = 1,
    LFEQUIPMENT_ID_UPRIGHT_BIKE = 2,
    LFEQUIPMENT_ID_RECUMBENT_BIKE = 3,
    LFEQUIPMENT_ID_CROSS_TRAINER = 4,
    LFEQUIPMENT_ID_F1_SMART_TREADMILL = 5 ,
    LFEQUIPMENT_ID_CONSUMER_LIFE_CYCLE = 6,
    LFEQUIPMENT_ID_CONSUMER_CROSS_TRAINER =7,
    LFEQUIPMENT_ID_T3_TREADMILL =8,
    LFEQUIPMENT_ID_F3_TREADMILL =9,
    LFEQUIPMENT_ID_SMART_LIFE_CYCLE = 10,
    LFEQUIPMENT_ID_SMART_CROSS_TRAINER = 11,
    LFEQUIPMENT_ID_SUMMIT_TRAINER = 12,
    LFEQUIPMENT_ID_STAIR_CLIMBS = 13,
    LFEQUIPMENT_ID_T5_TREADMILL = 14,
    LFEQUIPMENT_ID_FLEX_STRIDER = 15,
    LFEQUIPMENT_ID_POWER_MILL = 16,
    LFEQUIPMENT_ID_ROWER = 17,
    LFEQUIPMENT_ID_ARC_TRAINER = 18
} LFEquipmentId;

typedef enum LFPresetType
{
    LFPresetEquipment=0,
    LFPresetGPS = 1
}LFPresetType;


typedef enum LFCardioWorkoutType
{
    LFCardioWorkoutTypeOutdoor      = 0,
    LFCardioWorkoutTypeEquipment    = 1
}LFCardioWorkoutType;


typedef enum LFOutdoorWorkoutType
{
    LFOutdoorWorkoutTypeWalk      = 0,
    LFOutdoorWorkoutTypeRun    = 1,
    LFOutdoorWorkoutTypeCycle = 2
}LFOutdoorWorkoutType;


enum CardioProgramType {
    P_NONE = 0,
    P_QUICK_START = 1,
    P_HILL = 2,
    P_RANDOM = 3,
    P_MANUAL = 4,
    P_FAT_BURN = 5,
    P_CARDIO = 6,
    P_HR_HILL = 7,
    P_HR_INTERVAL = 8,
    P_EXTREME_HR = 9,
    P_WATTS = 10,
    P_METS = 11,
    P_AEROBICS = 12,
    P_REVERSE = 13,
    P_PT1 = 14,
    P_PT2 = 15,
    P_PT3 = 16,
    P_PT4 = 17,
    P_PT5 = 18,
    P_PT6 = 19,
    P_LF_FIT_TEST = 20,
    P_GERKIN = 21,
    P_PEB = 22,
    P_ARMY = 23,
    P_NAVY = 24,
    P_AIR_FORCE = 25,
    P_MARINE = 26,
    P_AROUND_THE_WORLD = 27,
    P_KILIMANJARO = 28,
    P_INTERVAL = 29,
    P_CASCADES = 30,
    P_SPEED_TRAINING = 31,
    P_FOOT_HILLS = 32,
    P_SPORT_TRAINING = 33,
    P_SPORT_TRAINING_5K = 34,
    P_SPORT_TRAINING_10K = 35,
    P_CUSTOM1 = 36,
    P_CUSTOM2 = 37,
    P_CUSTOM3 = 38,
    P_CUSTOM4 = 39,
    P_CUSTOM5 = 40,
    P_CUSTOM6 = 41,
    P_CUSTOM7 = 42,
    P_CUSTOM8 = 43,
    P_EZ_RESISTANCE = 44,
    P_SPEED_INTERVAL = 45,
    P_NET_ID = 46,
    P_LF_FIT_TEST_NOT_TRED = 47,
    P_AIR_FORCE_NOT_TRED = 48,
    P_NETWORK_PRESETS = 49,
    P_RANDOM_PLAY = 50,
    P_INTERVAL_RUN = 51,
    P_MOUNTAIN_TREK = 52,
    P_CREATE_YOUR_OWN = 53,
    P_WFI = 54,
    P_BRITISH_ARMY = 55,
    P_AIR_FORCE_WALK = 56,
    P_CREATE_YOUR_OWN_EX = 57,
    TotalProgram = 58,
    P_3_SPEED_INTERVAL = 59,
    P_FAMS  = 60,
    P_EZ_INCLINE=260,
    P_CALORIE_GOAL=261,
    P_DISTANCE_GOAL=262,
    P_TARGET_HR_GOAL=263
}CardioProgramType;



enum GoalTypes {
    
    NONE = 0,
    TIME = 1,
    DISTANCE = 2,
    CALORIES = 3,
    TIZ = 4,
    MARATHON_MODE = 5,
    DISTANCE_CLIMBED = 6,
    PACE = 10,
    INCLINE =11,
    LEVEL = 12,
    NAME=13,
    SPEED = 14,
    HEART_RATE =15,
    JOG_SPEED =16,
    RUN_SPEED =17,
    RUN_PHASE_SPEED =18,
    WALK_SPEED =19,
    ELEVATION = 20,
    WATTS = 21,
    METS=22
    
}GoalType;


enum LFWorkoutParams
{
    LFWorkoutParamsNone = 0,
    LFWorkoutParamsAge = 1,
    LFWorkoutParamsWeight = 2,
    LFWorkoutParamsGender = 3,
    LFWorkoutParamsDistance = 4,
    LFWorkoutParamsCalories = 5,
    LFWorkoutParamsPace = 6,
    LFWorkoutParamsTime = 7,
    LFWorkoutParamsTimeZone = 8,
    LFWorkoutParamsElevation = 9,
    LFWorkoutParamsMarathonMode = 10,
    LFWorkoutParamsIncline = 11,
    LFWorkoutParamsLevel = 12,
    LFWorkoutParamsHartRate = 13,
    LFWorkoutParamsInitialSpeed = 14,
    LFWorkoutParamsWalkSpeed = 15,
    LFWorkoutParamsJogSpeed = 16,
    LFWorkoutParamsRunSpeed = 17,
    LFWorkoutParamsTime_Distence = 18,
    LFWorkoutParamsPace_Time = 19,
    LFWorkoutParamsPace_Speed = 20,
    LFWorkoutParamsDistenced_Climbed = 21,
    LFWorkoutParamsFloor_Climbed = 22,
    LFWorkoutParamsInterval = 23,
    LFWorkoutParamsWatts = 24,
    LFWorkoutParamsMETs  = 25,
    LFWorkoutParamsActivity = 26,
    LFWorkoutParamsHeight = 27,
    LFWorkoutParamsRank = 28,
    LFWorkoutParamsScore = 29,
    LFWorkoutParamsRun_Time = 30,
    LFWorkoutParamsTest_Type = 31,
    LFWorkoutParamsStraidLength = 32,
    LFWorkoutParamsRepetition = 33,
    LFWorkoutParamsStrength = 34,
    LFWorkoutParamsSteps = 35,
    LFWorkoutParamsFloor = 36,
    LFWorkoutParams500MSplitTime = 37,
    LFWorkoutParamsStrokePerMin= 38,
    LFWorkoutParamsDistanceRX= 39,
    LFWorkoutParamsTrrain = 40,
    LFWorkoutParamsWorkoutBurnType = 41,
    //custom param
    LFWorkoutParamsIntervalType = 90,
    LFWorkoutParamsGoalType = 91,
    LFWorkoutParamsNumberOfIntervalType = 92,
    LFWorkoutParamsSpeedLevel = 93,
    LFWorkoutParamsFloorOrSteps = 94,
    LFWorkoutParamsIntervalTime = 95
    
}LFWorkoutParams ;


/**
 Enum for Parameters
 */

enum SegmentType {
    
    SEGMENT_TYPE_SPEED = 18,
    SEGMENT_TYPE_HEART_RATE = 19,
    SEGMENT_TYPE_LEVEL = 20,
    
}SegmentType;



typedef enum LFRequestType 
{
    LFAuthenticationRequestType = 1,
    LFWorkoutsListRequestType = 2,         // support for user workouts(LFUserWorkoutList) and Predefine workouts (LFPredefineWorkoutList) type
    LFWorkoutsDetailRequestType = 3,
    LFWorkoutResultRequestType = 4,
    LFUserRegisterRequestType = 5,
    LFDefaultPresetsDetailRequestType = 6, // not support
    LFFacilityRequestType = 7,             // not support
    LFGetProgressRequestType = 8,
    LFServiceAutherizarionType = 9,
    LFPredefineWorkoutRequestType = 10,    // not support
    LFValidateLicense = 11,
}LFRequestType;


enum ResponseType
{
    ResponseTypeNotUpdate = 0,
    ResponseTypeSuccees  = 1
}ResponseType;



typedef enum LFWorkoutTypes {
    LFUserWorkoutList = 0,
    LFPredefineWorkoutList = 1,
    LFGPSReplayWorkout
}LFWorkoutTypes;

enum LFQRTypes {
    LFQRTypeNonConnectedStrength = 0,
    LFQRTypeNonConnectedCardio,
    LFQRTypeCardioResult,
    LFQRTypeLoginDiscoverExplore,
    LFQRTypeLoginIntegrity,
    LFQRTypeNotSupport
}LFQRTypes;


enum LFQRLoginOption {
    LFQRLoginOptionBluetooth = 0,
    LFQRLoginOptionInternet = 1
}LFQRLoginOption;


typedef enum LFWotkoutIntensityType {
    LFIntensityExtreme  =  0,
    LFIntensityVigorous = 1,
    LFIntensityModerate = 2,
    LFIntensityLight,
}LFWotkoutIntensityType;



#define DEVICE_MODEL_TREADMILL              1
#define DEVICE_MODEL_CROSSTRAINER           2
#define DEVICE_MODEL_BIKE                   3
#define DEVICE_MODEL_POWER_MILL             4


@interface LFShared : NSObject
{
    
}

@end

