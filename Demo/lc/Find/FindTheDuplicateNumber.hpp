//
//  FindTheDuplicateNumber.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/12.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef FindTheDuplicateNumber_hpp
#define FindTheDuplicateNumber_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace FindTheDuplicateNumber {
/*
 数组中有一个重复的整数 转化为 判断 链表中存在环
 找到环入口处的数字，即为重复数字
 
 示例：
 数组：1,3,4,2,2
 下标：0 1 2 3 4
 f(0) -> 1
 f(1) -> 3
 f(3) -> 2
 f(2) -> 4
 f(4) -> 2
 must rewrite
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        else if (nums.size() ==2) {
            return nums[0];
        }
        
        int slow = 0;
        int fast = 0;

        slow = nums[slow];
        fast = nums[fast];
        fast = nums[fast];
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }
        
        int third = 0;
        while (third != slow) {
            slow = nums[slow];
            third = nums[third];
        }
        return third;
    }
};

}


#endif /* FindTheDuplicateNumber_hpp */
