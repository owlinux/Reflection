//
//  Reflection.h
//  Reflection
//
//  Created by DigiCAP on 2014. 11. 18..
//  Copyright (c) 2014년 DigiCAP. All rights reserved.
//

#import <Foundation/Foundation.h>


/// Security Level을 나타내는 5단계,
/// 'blank'는 라이브러리가 등록되지 않는 상태
typedef enum { blank, red, orange, yellow, black, green } SecurityLevel;


@protocol ReflectionDelegate <NSObject>

/// Security Level을 App에게 알려주기 위한 Delegate
- (void) updateSecurityLevel:(SecurityLevel) level;

@end



@interface Reflection : NSObject


/// 라이브러리 사용을 위한 단말 등록
- (BOOL) registerDevice:(id)delegate;


/// Security Level을 확인하기 위한 API
- (SecurityLevel) getSecurityLevel;

@end
