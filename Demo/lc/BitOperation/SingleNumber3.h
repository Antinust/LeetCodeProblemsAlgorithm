//
//  SingleNumber3.h
//  Demo
//
//  Created by zcc_imac on 2022/4/30.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SingleNumber3_h
#define SingleNumber3_h
#import "PublicCommon.h"

namespace SingleNumber3 {
/*
 1. 先求出所有元素的抑或和 xorSum，为a ^ b
 2. 然后求出xorSum 的最低位为1(其余位0)的数 设为lowesBitEqualOne，注意处理xorSum == INT_MIN的情况；设lowesBitEqualOne为1的位置为k
 3. 根据num[i]^lowesBitEqualOne == 1 / 0 把数组中所有的元素划分为两组，即第k位 为1 和不为1的，a，b必定在这不同的两组；
    最后结果为a ^= num[i]                 num[i]^lowesBitEqualOne == 1
            b ^= num[i]                  num[i]^lowesBitEqualOne == 0
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        int len = a.size();
        int xorSum = a[0];
        for (int i = 1; i < len; i++ ) {
            xorSum ^= a[i];
        }
        int lowestBitEqualOne = xorSum == INT_MIN ? xorSum : (xorSum & (-xorSum));
        int num1 = 0;
        int num2 = 0;
        for (const int num : a) {
            if (num &  lowestBitEqualOne) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        return vector<int> {num1, num2};
    }
};

}

#endif /* SingleNumber3_h */
