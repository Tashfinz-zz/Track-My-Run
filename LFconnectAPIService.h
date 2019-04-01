//
//  LFWebService.h
//  LFopen
//
//  Created by Dulip Gayan Dasanayaka on 20/4/15.
//  Copyright (c) 2015 Lifefitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFUser.h"
#import "LFShared.h"

@interface LFconnectAPIService : NSObject
{
    
}

@property (nonatomic, strong) NSString * secret;
@property (nonatomic, strong) NSString * token;
@property (nonatomic, strong) NSDictionary * headerFields;


/*
    Initialize
    accesstoken : Oauth access token:
    accessScret : Oauth access secret
 */
- (instancetype)initWith:(NSString*)accesstoken accessSecret:(NSString*)accessScret;


/*
 Initialize
 accesstoken : Oauth access token:
 accessScret : Oauth access secret
 info        : Additional headder fields
 */
- (instancetype)initWith:(NSString*)accesstoken accessSecret:(NSString*)accessScret info:(NSDictionary*)headerInfo;


/*
    Login
    email       :  LFconnect User email address
    password    :  Password
*/
- (void)loginWithUserEmail:(NSString*)email
                  password:(NSString*)password
                   success:(void (^)(LFUser * user, NSHTTPURLResponse *response))lfSuccess
                   failure:(void(^)(NSError* error, NSHTTPURLResponse* response))lfFailure;



/*
 Login
 xid            :  Netpuls xid
 password       :  Netpuls passcode
 */
- (void)loginWithUserXID:(NSString*)xid
                passcode:(NSString*)passcode
                 success:(void (^)(id responseObject, NSHTTPURLResponse *response))lfSuccess
                 failure:(void(^)(NSError* error,NSHTTPURLResponse* response))lfFailure;



/*
 Login
 QRcodestring            :  QR code string
 */
- (void)loginToConsoleWithInternetConnection:(NSString*)QRcodestring
                                     success:(void (^)(id responseObject, NSHTTPURLResponse *response))lfSuccess
                                     failure:(void(^)(NSError* error,NSHTTPURLResponse* response))lfFailure;



/*
 Login
 QRcodestring            :  QR code string
 pushNotificationToken   :  Push notification token for application
 */
- (void)loginToConsoleWithInternetConnection:(NSString*)QRcodestring
                       pushNotificationToken:(NSString*)pushToken
                                     success:(void(^)(id responseObject, NSHTTPURLResponse *response))lfSuccess
                                     failure:(void(^)(NSError* error,NSHTTPURLResponse* response))lfFailure;

/*
 Login
 user            :  LFuser object with necessary informations
 */

- (void)create_Update_User:(LFUser*)user
                   success:(void (^)(NSString * userId, NSHTTPURLResponse *response))lfSuccess
                   failure:(void(^)(NSError* error,NSHTTPURLResponse* response))lfFailure;


/*
 userId                  : lfconnect userid
 QRcodestring            :  QR code string
 result   :  user can login to discover console
 */
- (void)loginToConsoleWithUserId:(NSString*)userId
                 qr_string:(NSString*)QRcodestring
                   success:(void (^)(BOOL success, NSHTTPURLResponse *response))lfSuccess
                   failure:(void(^)(NSError* error,NSHTTPURLResponse* response))lfFailure;


/*
 xid                     : external identification id
 QRcodestring            :  QR code string
 result   :  user can login to discover console
 */
- (void)loginToConsoleWith_XID:(NSString*)xid
                     qr_string:(NSString*)QRcodestring
                       success:(void (^)(BOOL success, NSHTTPURLResponse *response))lfSuccess
                       failure:(void(^)(NSError* error,NSHTTPURLResponse* response))lfFailure;

@end
