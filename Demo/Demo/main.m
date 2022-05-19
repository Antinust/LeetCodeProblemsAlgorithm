//
//  main.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2019/1/17.
//  Copyright © 2019 Zhuo,Chuncai. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

/*
说明：C++ 中不再区分初始化和未初始化的全局变量、静态变量的存储区，如果非要区分下述程序标注在了括号中
*/

int g_var = 0; // g_var 在全局区（.data 段）
char *gp_var;  // gp_var 在全局区（.bss 段）

// 在iOS真机、模拟器上 堆栈的地址顺序不一样
//int main() {
//    int var;                    // var 在栈区
//    char *p_var;                // p_var 在栈区
//    char arr[] = "abc";         // arr 为数组变量，存储在栈区；"abc"为字符串常量，存储在常量区
//    char *p_var1 = "123456";    // p_var1 在栈区；"123456"为字符串常量，存储在常量区
//    static int s_var = 0;       // s_var 为静态变量，存在静态存储区（.data 段）
//    p_var = (char *)malloc(10); // 分配得来的 10 个字节的区域在堆区
//    NSLog(@"%p \r\n %p \r\n %p \r\n %p \r\n %p", &var, &p_var, arr, p_var1, &s_var);
//    NSLog(@"----------");
//    NSLog(@"%p ", p_var);
//    NSLog(@"%p \t %p", &g_var, &gp_var);
//    free(p_var);
//    return 0;
//}

extern void _objc_autoreleasePoolPrint();

#define TEST_AUTO_RELEASE_POOL 0

int main(int argc, char * argv[]) {

    //pool1，里面添加1个自动释放对象
    @autoreleasepool {
#if TEST_AUTO_RELEASE_POOL
        NSObject *obj = [[NSObject alloc] autorelease];

        //pool2，里面添加3个自动释放对象
        @autoreleasepool {

            NSInteger count = 3;
            for(NSInteger i=0; i<count; i++){

                NSObject *obj = [[NSObject alloc] autorelease];
            }

            //pool3，里面添加2个自动释放对象
            @autoreleasepool {

                NSInteger count = 2;
                for(NSInteger i=0; i<count; i++){

                    NSObject *obj = [[NSObject alloc] autorelease];
                }

                //创建完三个pool后打印
                _objc_autoreleasePoolPrint();
            }

            //超出pool3的作用域时打印
            _objc_autoreleasePoolPrint();
        }

        //超出pool2的作用域时打印
        _objc_autoreleasePoolPrint();
#else
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
#endif
    }
    //超出pool1作用域打印
    _objc_autoreleasePoolPrint();
    return 0;
}
