//
//  PalindromicSubstrings.h
//  Demo
//
//  Created by zcc_imac on 2022/4/5.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef PalindromicSubstrings_h
#define PalindromicSubstrings_h

#import "PublicCommon.h"

namespace PalindromicSubstrings {

/*
 1. 遍历字符串的回文中心，从0到2n-2，然后用两个index从回文中心往两侧扩展，直到不是回文
 回文中心可能是一个(回文个数是基数时)，两个(回文个数是偶数时)
 以n=4为例子, l=i/2 r=l+i%2
  编号i  左起始l  右起始r
     0    0    0
     1    0    1
     2    1    1
     3    1    2
     4    2    2
     5    2    3
     6    3    3
 
 + 的运算符优先级 高于& 注意
 */


class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int sum = 0;
        for (int i = 0; i <= 2 * len - 2; i++) {
            int l = i / 2;
            int r = l + (i & 1);
            while (l >= 0 && r < len && s[l] == s[r]) {
                l--;
                r++;
                sum++;
            }
        }
        return sum;
    }
};

}



#endif /* PalindromicSubstrings_h */
