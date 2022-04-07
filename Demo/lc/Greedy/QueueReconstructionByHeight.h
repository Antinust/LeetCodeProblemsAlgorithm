//
//  QueueReconstructionByHeight.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/6.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef QueueReconstructionByHeight_h
#define QueueReconstructionByHeight_h
#include "PublicCommon.h"

namespace QueueReconstructionByHeight {
/*
 1. 先插入高个的元素，高个的放置好后，再插入矮个的到位置k时，前面第k-1个元素必定都比自己高；
 二维数组先按高度降序排列，高度相同k位置小的放前面
 
 */
//    struct cmp {
//        bool operator() (const vector<int>& v1, const vector<int>& v2) {
//            return v1[0] > v2[0];
//        }
//    };

class Solution {
public:
    // https://blog.csdn.net/u010982765/article/details/79021426
    // 因为成员函数有个隐藏的this函数指针参数，若不声明为static，函数参数个数不匹配
    static bool sortcmp(const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] == v2[0]) {
            return v1[1] < v2[1];
        } else {
            return v1[0] > v2[0];
        }
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>>ans;
        sort(people.begin(), people.end(), sortcmp);
        
        list<vector<int>> l;
        for (int i = 0; i < people.size(); i++) {
            if (l.size() <= people[i][1]) {
                l.push_back(people[i]);
            } else {
                l.insert(next(l.begin(), people[i][1]), people[i]);
            }
        }
        for (auto it = l.begin(); it != l.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};

}

#endif /* QueueReconstructionByHeight_h */
