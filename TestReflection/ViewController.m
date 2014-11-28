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

@end


@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    Reflection *reflection = [[Reflection alloc] init];
    [reflection registerDevice:self];
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
}

@end
