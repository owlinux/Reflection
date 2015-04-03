//
//  ViewController.m
//  TestReflection
//
//  Created by DigiCAP on 2014. 11. 24..
//  Copyright (c) 2014년 DigiCAP. All rights reserved.
//

#import "ViewController.h"
#import "Reflection.h"


@interface ViewController () <ReflectionDelegate>
@property (nonatomic, strong) Reflection *reflection;
@end


@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _reflection = [[Reflection alloc] init];
    
    NSString *resourcePath = [[NSBundle mainBundle] pathForResource:@"App_I_5cd0c8a5236ec554_1.0.1" ofType:@"p12"];
    NSData *p12Data = [NSData dataWithContentsOfFile:resourcePath];
    [_reflection registerDevice:self certData:p12Data];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark -
#pragma mark - Reflection Delegate
#pragma mark -

- (void) updateSecurityLevel:(SecurityLevel)level {
    
    NSLog(@"updateSecurityLevel Call");
    NSLog(@"Current Security Level : %d", level);
    [_reflection requestCpKey];
}

- (void) setCpKey:(NSData *)cpKey resultCode:(int)code resultMsg:(NSString *)description
{
    NSLog(@"setCpKey");
    
    NSString *cpKeyStr = [[NSString alloc] initWithData:cpKey encoding:NSUTF8StringEncoding];

    NSLog(@"CP Key : %@", cpKeyStr);
    
    [_reflection requestHeadUnit:@"H" mac:@"0019B8015F7D" sig:@"signatureData"];
}

- (void) responseHeadUnit:(NSData *)responseData keyData:(NSString *)cpKey resultCode:(int)code resultMsg:(NSString *)description
{
    NSLog(@"responseHeadUnit");
}

@end
