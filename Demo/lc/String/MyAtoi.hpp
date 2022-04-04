//
//  MyAtoi.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/3.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MyAtoi_hpp
#define MyAtoi_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace MyAtoi {
/*
 1. 在 累加求和 及 计算每一位 的过程中，可能出现溢出，需要提前处理
 */

class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int64_t num = 0;
        int index = 0;
        bool isPositive = true;
        string validS;
        while (index < s.length() && s[index] == ' ') {
            index++;
        }
        if (index >= s.length()) {
            return num;
        }
        if (s[index] == '-' || s[index] == '+') {
            isPositive = s[index] == '+';
            index++;
        }
        while (index < s.length() && s[index] >= '0' &&  s[index] <= '9') {
            validS.append(string(1, s[index]));
            index++;
        }
        if (validS.length() > 0) {
            int length = validS.length();
            for (int i = length - 1; i >= 0; i--) {
                if (validS[i] != '0') {
                    int kth = length - i - 1;
                    if (kth > 9) {
                        return isPositive ? INT_MAX : INT_MIN;
                    }
                    num += (int64_t)pow(10, kth) * (validS[i] - '0'); // pow前的转换应该是(int64_t)
                }
            }
            if (isPositive) {
                if (num >= INT_MAX) {
                    return INT_MAX;
                }
            } else {
                if (-num <= INT_MIN) {
                    return INT_MIN;
                }
            }
        }
        return isPositive ? num : -num;
    }
};

}

#endif /* MyAtoi_hpp */
