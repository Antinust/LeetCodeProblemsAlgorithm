//
//  LongestRepeatingCharacterReplacement.h
//  Demo
//
//  Created by zcc_imac on 2022/4/30.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LongestRepeatingCharacterReplacement_h
#define LongestRepeatingCharacterReplacement_h
#import "PublicCommon.h"
namespace LongestRepeatingCharacterReplacement {
/*
 滑动窗口：不满足条件时，左指针右移，满足条件时右指针右移，直到找到最大的maxCnt
 需要用FreqArray 记录 滑动窗口内 字母的频率
 
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxCnt = 0;
        
    }
};

}

#endif /* LongestRepeatingCharacterReplacement_h */
