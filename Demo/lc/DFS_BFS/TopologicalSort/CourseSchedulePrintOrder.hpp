//
//  CourseSchedulePrintOrder.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/6.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef CourseSchedulePrintOrder_hpp
#define CourseSchedulePrintOrder_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace CourseSchedulePrintOrder {

class Solution {
    const static int MAX_LENGTH = 2001;
public:
    Solution() {
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        multimap<int, int> mMap;
        vector<int> mV;
        vector<int> emptyVec;
        queue<int> mQ;

        int totalCnt = (int)prerequisites.size();
        
        int indegrees[MAX_LENGTH] = {0};
        bool visited[MAX_LENGTH] = {0};
        memset(visited, 1, sizeof(visited));
        memset(indegrees, 0, sizeof(indegrees));

        // 用 new的方式 在leetCode提交不行，不知道为啥?
//        int *indegrees = new int[numCourses + 1];
//        int *visited = new int [numCourses + 1]; // 标记输入了的courseID
//        for (int i = 0; i < totalCnt; i++) {
//            visited[i] = 1;
//            indegrees[i] = 0;
//        }
        
        for (int i = 0; i < totalCnt; i++) {
            int latter = prerequisites[i][0];
            int former = prerequisites[i][1];
            indegrees[latter]++;
            visited[latter] = visited[former] = 0;
            mMap.insert(make_pair(former, latter));
        }
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 1) {
                mV.push_back(i);
            }
            else if (visited[i] == 0 && indegrees[i] == 0) {
                mQ.push(i);
            }
        }
        
        while (!mQ.empty()) {
            int i = mQ.front();
            mV.push_back(i);
            visited[i] = 1;
            
            auto ret = mMap.equal_range(i);
            for (std::multimap<int,int>::iterator it=ret.first; it!=ret.second; ++it) {
                indegrees[it->second]--;
                if (indegrees[it->second] == 0) {
                    mQ.push(it->second);
                }
            }
            mQ.pop();
        }
        
        int visitedCourses = 0;
        for (int i = 0; i < numCourses; i++) {
            if (visited[i]) {
                visitedCourses++;
            }
        }
//        delete [] indegrees;
//        delete [] visited;
        return visitedCourses >= numCourses ? mV : emptyVec;
    }
};

}

#endif /* CourseSchedulePrintOrder_hpp */
