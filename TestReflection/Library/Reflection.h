//
//  Reflection.h
//  Reflection
//
//  Created by DigiCAP on 2014. 11. 18..
//  Copyright (c) 2014년 DigiCAP. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kDeviceId           @"device_id"
#define kDeviceType         @"device_type"
#define kDeviceEnv          @"device"
#define kAppId              @"app_id"
#define kAppVersion         @"app_version"
#define kInitFlag           @"init_flag"
#define kSignature          @"digital_signature"
#define kCommonName         @"cm_name"

#define kBaseUrl            @"https://221.133.61.202:443/"
#define kReqInitCert        @"initCert.do"
#define kReqInitReg         @"initReg.do"
#define kReqAuthCert        @"certCon.do"


#define kCertFilePath       @"Cert.p12"


/// Security Level을 나타내는 5단계,
/// 'blank'는 라이브러리가 등록되지 않는 상태
typedef enum { blank, red, orange, yellow, black, green } SecurityLevel;

/// Auth Server로 요청하는 타입
typedef enum
{
    INIT_CERTIFICATE = 0,       /// initCert.do
    INIT_REGISTER,              /// initReg.do
    AUTH_CERTIFICATE            /// certCon.do
} RequestType;


@protocol ReflectionDelegate <NSObject>

/// Security Level을 App에게 알려주기 위한 Delegate
- (void) updateSecurityLevel:(SecurityLevel) level;

/// CP Key를 전달해주기 위한 Delegate
- (void) setCpKey:(NSData *)cpKey resultCode:(int)code resultMsg:(NSString *)description;

@end


@interface Reflection : NSObject<NSURLConnectionDelegate>


/// 라이브러리 사용을 위한 단말 등록
- (BOOL) registerDevice:(id)delegate certData:(NSData *)data;

/// 서버로부터 CP Key를 요청하기 위한 API
- (BOOL) requestCpKey;

/// Security Level을 확인하기 위한 API
- (SecurityLevel) getSecurityLevel;

@end
