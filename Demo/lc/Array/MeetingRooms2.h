//
//  MeetingRooms2.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/7.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MeetingRooms2_h
#define MeetingRooms2_h

#include "PublicCommon.h"
namespace MeetingRooms2 {
/*
 1. sort all starts and ends; when a.end == b.start, place a.end in front
    set cnt=0;
    cnt++ when meeting start
    cnt-- when meeting end
    record maxValue
 */

class Solution {
public:
    static bool cmp(const pair<int, int> &a , const pair<int, int> &b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>>num;
        for (int i = 0; i < intervals.size(); i++) {
            num.push_back(make_pair(intervals[i][0], 0));
            num.push_back(make_pair(intervals[i][1], 1));
        }
        sort(num.begin(), num.end(), cmp);
        int cnt = 0;
        int maxNumRoomNeeded = 0;
        for (int i = 0; i < num.size(); i++) {
            if (num[i].second == 0) {
                cnt++;
            } else {
                cnt--;
            }
            maxNumRoomNeeded = max(cnt, maxNumRoomNeeded);
        }
        return maxNumRoomNeeded;
    }
};

//class Solution {
//public:
////    static bool cmp(const pair<int, int> &a , const pair<int, int> &b) {
////        if (a.first == b.first) {
////            return a.second > b.second;
////        }
////        return a.first < b.first;
////    }
//    static bool cmp(const vector<int> &v1 , const vector<int> &v2) {
//        if (v1[0] == v2[0]) {
//            return v1[1] > v2[1];
//        }
//        return v1[0] < v2[0];
//    }
//    int minMeetingRooms(vector<vector<int>>& intervals) {
////        vector<pair<int, int>>num;
//        vector<vector<int>>num;
//
//        for (int i = 0; i < intervals.size(); i++) {
////            num.push_back(make_pair(intervals[i][0], 0));
////            num.push_back(make_pair(intervals[i][1], 1));
//            num.push_back(vector<int>{intervals[i][0], 0});
//            num.push_back(vector<int>{intervals[i][1], 1});
//        }
//        sort(num.begin(), num.end(), cmp);
//        int cnt = 0;
//        int maxNumRoomNeeded = 0;
//        for (int i = 0; i < num.size(); i++) {
//            if (num[i][1] == 0) {
//                cnt++;
//            } else {
//                cnt--;
//            }
//            maxNumRoomNeeded = max(cnt, maxNumRoomNeeded);
//        }
//        return maxNumRoomNeeded;
//    }
//};

}

#endif /* MeetingRooms2_h */
