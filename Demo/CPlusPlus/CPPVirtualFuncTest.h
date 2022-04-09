//
//  CPPVirtualFuncTest.h
//  Demo
//
//  Created by zcc_imac on 2022/4/9.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef CPPVirtualFuncTest_h
#define CPPVirtualFuncTest_h
#import "PublicCommon.h"

namespace CPPVirtualFuncTest {

class A {
public:
    virtual void vfunc1(){ cout<<"A:vfunc1"<<std::endl; }
    virtual void vfunc2(){ cout<<"A:vfunc2"<<std::endl; }
            void func1(){  }
            void func2(){  }
    
private:
    int m_data1, m_data2;
};

class B : public A {
public:
    virtual void vfunc1(){ cout<<"B:vfunc1"<<std::endl; }
            void func2(){  }
private:
    int m_data3;
};

class C : public B {
public:
    virtual void vfunc1(){ cout<<"C:vfunc1"<<std::endl; }
            void func2(){  }
private:
    int m_data1, m_data4;
};

}



class Base1
{
public:
    int base1_1;
    int base1_2;

    virtual void vf1() {}
    virtual void vf2() {}
};

class Base2
{
public:
    int base2_1;
    int base2_2;

    virtual void b2_vf1() {}
    virtual void b2_vf2() {}
};

// 多继承
class Derive1 : public Base1, public Base2
{
public:
    int derive1_1;
    int derive1_2;

    // 基类虚函数覆盖
    virtual void vf1() {}
    virtual void b2_vf2() {}

    // 自身定义的虚函数
    virtual void d_vf1() {}
    virtual void d_vf2() {}
};



#endif /* CPPVirtualFuncTest_h */
