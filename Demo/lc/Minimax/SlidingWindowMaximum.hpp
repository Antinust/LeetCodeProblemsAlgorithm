//
//  SlidingWindowMaximum.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/4.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SlidingWindowMaximum_hpp
#define SlidingWindowMaximum_hpp



#include <stdio.h>
#include "PublicCommon.h"

class Solution4 {
    struct Node {
        int key = 0;
        int index = 0;
        Node(int k, int ind):key(k), index(ind) { }
        
        bool operator> (const Node &b) const {
            return this->key > b.key;
        }
        
        bool operator< (const Node &b) const {
            return this->key < b.key;
        }
    };
    
    priority_queue<Node> maxQ;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>v;

        int totalCnt = (int)nums.size();
        for (int i = 0; i < k; i++) {
            maxQ.push(Node(nums[i], i));
        }
        v.push_back(maxQ.top().key);
        
        for (int i = 1; i <= totalCnt - k; i++) {
            int windowRightBorderIndex = i + k -1;
            maxQ.push(Node(nums[windowRightBorderIndex], windowRightBorderIndex));
            int topNodeIndex = maxQ.top().index;
            if (topNodeIndex >= i &&  topNodeIndex <= i + k -1) { // in range;
                v.push_back(maxQ.top().key);
            } else {
                while (!maxQ.empty() && (maxQ.top().index < i)) {
                    maxQ.pop();
                }
                v.push_back(maxQ.top().key);
            }
        }
        return v;
    }
};

#endif /* SlidingWindowMaximum_hpp */
