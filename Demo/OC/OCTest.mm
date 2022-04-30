//
//  OCTest.m
//  Demo
//
//  Created by zcc_imac on 2022/4/24.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "OCTest.h"
#import "CopyTest.h"



@implementation OCBase
@end

typedef union UTest {
    unsigned char d8;
    struct {
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
        unsigned char b8:1;

    } b;
};

@interface OCTest () {
    NSString *_foo;
//    NSString *foo;
}

@end

@implementation OCTest

- (instancetype)init {
    self = [super init];
    if (self) {
        NSLog(@" class: %@", NSStringFromClass([self class]));
        NSLog(@" class: %@", NSStringFromClass([super class]));
        [self copyTest];
        [self ivarTest];
        [self newTest];
        [self sizeTest];
    }
    return self;
}

- (void)newTest {
    int *p1 = new int[10];
    int *p2 = new int[10]();
    for (int i = 0; i < 10; i++) {
        printf("p1:%d p2:%d \r\n", *(p1 + i), *(p2 + i));
    }
}


void Func(char str_arg[100])
{
       printf("size:%d\n",sizeof(str_arg));
}

- (void)sizeTest {

    char str[]="Hello";
    printf("size1: %d\n",sizeof(str));
    printf("size2: %d\n",strlen(str));
    char*p=str;
    printf("size3: %d\n",sizeof(p));
    Func(str);
}

- (void)UnionTest {
//二进制   0b 0b10001101
//八进展    0
//十六进展    0x
    UTest ut = { 07 };
    int oct = 011;
    
    NSLog(@"ut:%d %d %d\r\n", ut.b.b1, ut.b.b2, ut.b.b3);
}

- (void)copyTest {
    CopyTest *test = [CopyTest new];
}

- (void)ivarTest {
    // key is foo
    [self setValue:nil forKey:@"foo"];
    NSLog(@" _foo: %@", _foo);
    
    [self setValue:@"foo1" forKey:@"foo"];
    NSLog(@" _foo: %@", _foo);
//    NSLog(@" foo: %@", foo);

    [self setValue:@"foo2" forKey:@"_foo"];
    NSLog(@" _foo: %@", _foo);
}


@end
