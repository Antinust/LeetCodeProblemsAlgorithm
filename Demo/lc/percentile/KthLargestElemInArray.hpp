//
//  KthLargestElemInArray.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/13.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef KthLargestElemInArray_hpp
#define KthLargestElemInArray_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace KthLargestElemInArray {

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return nums[0];
        }
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
//        int kthElem = 0;
        while (--k > 0 && !pq.empty()) {
            pq.pop();
        }
        return pq.top();
    }
};
}
#endif /* KthLargestElemInArray_hpp */
