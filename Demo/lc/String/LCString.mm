//
//  LCString.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/3.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "LCString.h"
#include <string>
#include <iostream>
#include <sstream>


@implementation LCString
- (instancetype)init
{
    self = [super init];
    if (self) {
        [self testForLC_split];
    }
    return self;
}

- (void)testForLC_split {
    std::istringstream ss("I wanna make a difference"); // included in sstream
    std::string str;
    while (std::getline(ss, str, ' ')) {
        std::cout<< str << std::endl;
    }
    std::cout << "test";
}

@end
