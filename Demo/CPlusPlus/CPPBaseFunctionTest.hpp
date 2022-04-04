//
//  CPPBaseFunctionTest.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/27.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef CPPBaseFunctionTest_hpp
#define CPPBaseFunctionTest_hpp

#include <stdio.h>
#include "PublicCommon.h"
#include <iostream>
using namespace std;

class base {
public:
    base() {
        cout << "base constructor" << endl;
        b = new int[5];
    }
     ~base() {
        cout << "base destructor" << endl;
        delete[] b;
    }

private:
    int *b;
};

class derived : public base {
public:
    derived() {
        cout << "derived constructor" << endl;
        d = new int[8];
    }
     ~derived() {
        cout << "derived destructor" << endl;
        delete[] d;
    }

private:
    int *d;
};

#endif /* CPPBaseFunctionTest_hpp */
