//
//  JumpGame.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/14.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef JumpGame_hpp
#define JumpGame_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace JumpGame {
/*
 1. 记录从index为0的位置开始 到 当前位置 能够跳的最大距离， 若当前的index已经大于 能跳的最大距离了，则不可达， 若存在一个元素可以跳到最后一个元素则返回true
 
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        int maxDistanceReachable = 0;
        int totalCnt = (int)nums.size() - 1;
        // 注意边界条件的处理
        for (int i = 0; i < totalCnt; i++) {
            if (i > maxDistanceReachable) {
                return false;
            }
            maxDistanceReachable = std::max(maxDistanceReachable, i + nums[i]);
            
            if (maxDistanceReachable >= totalCnt) { //可注释
                return true;
            }
        }
        return maxDistanceReachable >= totalCnt;
    }
};


//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        if (nums.size() == 1) {
//            return true;
//        }
//        int reachable[10001] = {0};
//        reachable[0] = 1;
//        int totalCnt = (int)nums.size() - 1;
//        // 注意边界条件的处理
//        for (int i = 0; i < totalCnt; i++) {
//            if (reachable[i] == 1 && nums[i] > 0) {
//                if (i + nums[i] >= totalCnt) {
//                    return true;
//                }
//                for (int j = i + 1; j <= i + nums[i]; j++) {
//                    reachable[j] = 1;
//                }
//            }
//        }
//        return false;
//    }
//};

}

#endif /* JumpGame_hpp */
