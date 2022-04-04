//
//  KthLargest.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/3.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef KthLargest_hpp
#define KthLargest_hpp

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
private:
    priority_queue<int> maxQueue;
    priority_queue<int, vector<int>, greater<int>> minQueue;
    
    int _maxQueueNum = 0;
    int _minQueueNum = 0;
    int _kth;
    unsigned int _totalCount = 0;

public:
    void updateQueueWithNum(int num) {
        if (maxQueue.empty() || _minQueueNum == 0) {
            maxQueue.push(num);
        } else if (minQueue.empty()) {
            // num -> right
            if (num >= maxQueue.top()) {
                minQueue.push(num);
            } else {
                minQueue.push(maxQueue.top());
                maxQueue.pop();
                maxQueue.push(num);
            }
        } else if (maxQueue.size() < _maxQueueNum) {
            if (num <= minQueue.top()) {
                maxQueue.push(num);
            } else if (minQueue.size() < _minQueueNum) {
                minQueue.push(num);
            } else {
                //force num -> left only when right is full
                maxQueue.push(minQueue.top());
                minQueue.pop();
                minQueue.push(num);

            }
        } else {
            // num -> right
            if (num > maxQueue.top()) {
                minQueue.push(num);
            } else {
                minQueue.push(maxQueue.top());
                maxQueue.pop();
                maxQueue.push(num);
            }
        }
    }
    
    void updateTotalCnt(int totalCnt) {
        _totalCount = totalCnt;
        _maxQueueNum = _totalCount - _kth + 1;
        _minQueueNum = _kth - 1;
    }
    
    KthLargest(int k, vector<int> &nums) {
        _kth = k;
        updateTotalCnt((unsigned int)nums.size());

        // set for queues
        for (int i = 0; i < nums.size(); i++) {
            updateQueueWithNum(nums[i]);
        }
    }
    
    int add(int val) {
        updateTotalCnt(_totalCount + 1);
        
        updateQueueWithNum(val);
        int ret = maxQueue.top();
//        printf("ret:%d\r\n", ret);
        return ret;
    }
};

#endif /* KthLargest_hpp */
