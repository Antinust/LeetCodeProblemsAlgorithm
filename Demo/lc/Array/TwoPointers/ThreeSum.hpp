//
//  ThreeSum.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/24.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef ThreeSum_hpp
#define ThreeSum_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace ThreeSum {
/*
 1. i 从0到n-3，设置L、R为index+1、n-1
    若sum=num[i]+num[l]+num[r] < 0 则说明L偏小，L++
    若sum > 0 则说明R偏大 R--
    若sum = 0，则L++且R--，否则找不到和为0的index：如只L++，对于当前R找不到更小的L；只R--，对于当前L找不到更大的R
    当num[i]=num[i-1]时跳过，因为需要排除重复项目
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        if (nums.size() < 3) {
            return vec;
        }
        std::sort(nums.begin(), nums.end());
        int totalCnt = (int)nums.size();
        for (int i = 0; i < totalCnt - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
//                i++; 这里的i++会导致i+=2 不需要i++，只需要continue即可，或者直接用while处理，不要夹杂
                continue;
            }
//            上面用while循环遍历之后，可能i、l会超出数组界限，需要及时continue或 如下面的break
//            if (i >= totalCnt - 2) {
//                break;
//            }
            int l = i + 1;
            int r = totalCnt - 1;
            int sum = nums[i] + nums[l] + nums[r];
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    vec.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l] == nums[l-1]) {
                        l++;
                    }
                    r--;
                    while (l < r && nums[r] == nums[r+1]) {
                        r--;
                    }
                } else if(sum < 0) {
                    l++;
                    while (l < r && nums[l] == nums[l-1]) {
                        l++;
                    }
                } else {
                    r--;
                    while (l < r && nums[r] == nums[r+1]) {
                        r--;
                    }
                }
            }
        }
        return vec;
    }
};

}

#endif /* ThreeSum_hpp */
