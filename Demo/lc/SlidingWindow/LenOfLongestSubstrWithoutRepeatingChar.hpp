//
//  LenOfLongestSubstrWithoutRepeatingChar.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/31.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LenOfLongestSubstrWithoutRepeatingChar_hpp
#define LenOfLongestSubstrWithoutRepeatingChar_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace LenOfLongestSubstrWithoutRepeatingChar {
/*
 1. 使用两个index：left、right，分别指向滑动窗口的左右两侧边界
 2. 使用hashMap存储当前不重复的元素，插入之前若元素已经存在更新left为当前相同元素上一次出现的index+1，注意这里必须跟之前的lIndex比较，否则在abba这个case下lIndex会往前多走一个元素，即条件为lIndex=max(lIndex, map[str[i]]+1)
 
    right为当前插入元素的index；同时更新right-left+1的最大值
 
 "abba"
 ""
 */

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_map<string, int>map;
        int maxLen = 0; //注意初始值
        int lIndex = 0;
        for (int i = 0; i < str.length(); i++) {
            string tempStr = string(1, str[i]);
            if (map.count(tempStr)) {
                lIndex = max(lIndex, map[tempStr] + 1); // 解决abba特殊case
            }
            map[tempStr] = i;
            maxLen = max(maxLen, i - lIndex + 1);
        }
        return maxLen;
    }
};
}

#endif /* LenOfLongestSubstrWithoutRepeatingChar_hpp */
