//
//  TaskScheduler.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/7.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef TaskScheduler_h
#define TaskScheduler_h
#include "PublicCommon.h"

namespace TaskScheduler {

/*
 1. 找到出现最大次数的字母的个数 为numOfMaxVal，最大次数为maxFrequency，最小出现间距为n，tasks任务数为taskCnt则有如下：
 ans = max(taskCnt, (maxFrequency - 1) * (n + 1) + numOfMaxVal)
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int taskCnt = tasks.size();
        if (n == 0) {
            return taskCnt;
        }
        unordered_map<int, int>map;
//        set<char> set;
        int maxFrequency = INT_MIN;
        int numOfMaxVal = 0;
        for (int i = 0; i < taskCnt; i++) {
            int tempVal = ++map[tasks[i]];
            if (tempVal >= maxFrequency) {
                maxFrequency = tempVal;
//                set.insert(tasks[i]);
            }
        }
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second == maxFrequency) {
                numOfMaxVal++;
            }
        }
        return max(taskCnt, (maxFrequency - 1) * (n + 1) + numOfMaxVal);
    }
};

}


#endif /* TaskScheduler_h */
