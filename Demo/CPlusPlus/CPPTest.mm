//
//  CPPTest.m
//  Demo
//
//  Created by zcc_imac on 2022/4/9.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "CPPTest.h"
#import "CPPVirtualFuncTest.h"

@implementation CPPTest

using namespace CPPVirtualFuncTest;

typedef void (*PFunc)(void);

- (instancetype)init
{
    self = [super init];
    if (self) {
//        [self test_vf];
        test_vfunc();
        test_class_size();
    }
    return self;
}

- (void)test_vf {
//    A* pa = new B;
//    pa->vfunc1();
//
//    B b;
//    pa = &b;
//    pa->vfunc1();
}

void test_vfunc() {
    C d1;
    C* pd1 = &d1;
//    pd1->d_vf2();
    
    auto virtualTableAddress = *(int64_t*)(pd1);
    std::cout << "0x" << std::hex << virtualTableAddress << std::endl;

//  https://blog.csdn.net/haoel/article/details/1948051
//  https://blog.csdn.net/qianghaohao/article/details/51356718

    for (int i = 0; i < 2; ++i){
        auto address = *(int64_t*)(virtualTableAddress + 8 * i);
        std::cout << "fun_" << i << " address: 0x" << std::hex << address << std::endl;
        PFunc pf = (PFunc) address;
        pf();
    }
    
//    A* pa = new A;
//
//    pa->vfunc1();
//
//    B b;
//    pa = &b;
//    pa->vfunc1();
//    pa->vfunc2();

}

/*
说明：程序是在 64 位编译器下测试的
*/
using namespace std;

class A
{
private:
    static int s_var; // 不影响类的大小
    const int c_var;  // 4 字节
    int var;          // 8 字节 4 + 4 (int) = 8
    char var1;        // 12 字节 8 + 1 (char) + 3 (填充) = 12
public:
    A(int temp) : c_var(temp) {} // 不影响类的大小
    ~A() {}                    // 不影响类的大小
};

class B
{
};

struct D {
    char a;
    int b;
    static double c; //静态成员
};

int test_class_size()
{
//    A ex1(4);
//    B ex2;
//    B *b1 = new B;
//
//    cout << sizeof(ex1) << endl;    // 12 字节
//    cout << sizeof(ex2) << endl;    // 1 字节
//    cout << sizeof(*b1) << endl;    // 1 字节
//    cout << sizeof(D) << endl;      // 8 字节

    return 0;
}

@end
