//
//  MergeIntervals.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/13.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MergeIntervals_hpp
#define MergeIntervals_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace MergeIntervals {
/*
 1. sort
 2. 新建一个vector存储比较结果即可
 */
class Solution {
public:
    static bool compare(const vector<int> &v1,  const vector<int>&v2) {
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> vec;
        if (intervals.size() <= 1) {
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end(), compare);
        
        vec.push_back(intervals[0]);
        int cnt = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (vec[cnt][1] >= intervals[i][0]) {
                int end = std::max(vec[cnt][1], intervals[i][1]);
                vec[cnt][1] = end;
            } else {
                vec.push_back(intervals[i]);
                cnt++;
            }
        }
        return vec;
    }
};

}

#endif /* MergeIntervals_hpp */
