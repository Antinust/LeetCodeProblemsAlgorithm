//
//  OCTest.m
//  Demo
//
//  Created by zcc_imac on 2022/4/24.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "OCTest.h"
#import "CopyTest.h"
#import <objc/runtime.h>

@interface TGetClass : NSObject

@end

@implementation TGetClass

@end


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
//    NSString *foo
}
@property int num;

@end

@implementation OCTest

- (void)startCountDown
{

    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        NSTimer* timer = [NSTimer timerWithTimeInterval:1 target:self selector:@selector(updateCountdownLabel:) userInfo:nil repeats:YES];
        [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSRunLoopCommonModes];
    });
}

- (void)updateCountdownLabel:(NSTimer*)timer
{
    static int cnt = 0;
    NSLog(@"updateCountdownLabel_cnt:%d", ++cnt);
    if(cnt >= 10)
    {
        dispatch_async(dispatch_get_global_queue(0, 0), ^{
            [timer invalidate];
        });
    }
}

- (void)test_runloop {
    NSLog(@"1");
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        NSLog(@"2");
        [[NSRunLoop currentRunLoop] run];
        [self performSelector:@selector(test) withObject:nil afterDelay:0.1];
        NSLog(@"3");
    });
    NSLog(@"4");
}

- (void)test{
    NSLog(@"5");
}

- (void)test_stackOverFlow {
//    dispatch_async(dispatch_get_global_queue(0, 0), ^{
//        char dp[512 * 1024] = {0};
//    });
    
}

- (void)test_add {
    int a=5, b;
    b = (++a) + (++a);
    printf("b:%d\r\n", b);
}

- (void)test_gcd {
    while (self.num < 5) {
        dispatch_async(dispatch_get_global_queue(0, 0), ^{
            NSLog(@"num_%d thread_id:%p", self.num, [NSThread currentThread]);
            self.num++;
        });
    }
    NSLog(@"num:%d", self.num);
}

- (void)test_gcd2 {
    for (int i = 0; i < 10000; i++) {
        dispatch_async(dispatch_get_global_queue(0, 0), ^{
            NSLog(@"num_%d thread_id:%p", self.num, [NSThread currentThread]);
            self.num++;
        });
    }
//    while (self.num < 5) {
//        dispatch_async(dispatch_get_global_queue(0, 0), ^{
//            NSLog(@"num_%d thread_id:%p", self.num, [NSThread currentThread]);
//            self.num++;
//        });
//    }
    NSLog(@"num:%d", self.num);
}

- (void)test_getClass {
    /*
     1. object_getClass 返回的是对象(传入参数) 属于哪个类
     2. objc_getClass  返回的是类对象，The Class object for the named class
     */
    TGetClass *obj = [TGetClass new];
    
//    objc_getClass()、object_getClass()、Class
    
    // test Class
//    NSLog(@"class_obj0:%p", [obj class]);

    NSLog(@" ");

    // test objc_getClass
    NSLog(@"class_obj1:%@", obj);
    NSLog(@"class_obj1:%@", [obj class]);
    
    NSLog(@" ");

    NSLog(@"class_obj1_2:%@", self);
//    NSLog(@"class_obj1_2:%p", super);
    NSLog(@"class_obj1_2:%@", [self class]);
    NSLog(@"class_obj1_2:%@", [super class]);
    
    NSLog(@" ");

    NSLog(@"class_obj1_3:%p", objc_getClass(object_getClassName(obj) ));
    NSLog(@"class_obj1_4:%p", objc_getClass(object_getClassName([obj class] ) ));

    NSLog(@" ");

    
    // test object_getClass
    NSLog(@"class_obj3_1:%p", object_getClass(obj));                            // 对象的isa 指向类 ： 类地址
    NSLog(@"class_obj3_2:%p", object_getClass([obj class]) );                   // 类的isa 指向元类 ： 元类地址
    
    NSLog(@"class_obj3_3:%p", object_getClass( object_getClass([obj class]) )); // 元类的isa 指向根元类 ： 根元类地址
    NSLog(@"class_obj3_4:%p", object_getClass([NSObject class]));                   // NSObject类的isa 指向根元类 ： 根元类地址
    NSLog(@"class_obj3_5:%p", object_getClass( object_getClass([NSObject class])) ); // 根元类的isa 指向根元类 ： 根元类地址

    NSLog(@" ");


}


- (instancetype)init {
    self = [super init];
    if (self) {
//        [self test_gcd];
//        [self test_gcd2];

        [self test_getClass];
        [self test_runloop];

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
