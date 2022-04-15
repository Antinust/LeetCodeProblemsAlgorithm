//
//  GroupAnagrams.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/26.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef GroupAnagrams_hpp
#define GroupAnagrams_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace GroupAnagrams {

/*
 1. map直接记录<sortedStr, unSortedStr>比记录<sortedStr, unSortedStrIndex>要好
    定义unordered_map<string, vector<string> > map 直接使用map[sortedStr].push_back(str[i]); 
 
 2. 将每个字母出现的次数使用字符串表示，作为哈希表的键 unordered_map<array<int, 26>, vector<string>>
 */

class Solution {
public:
    unordered_map<string, vector<string>> map;
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        map.clear();
        vector<vector<string>> ans;
        for (int i = 0; i < str.size(); i++) {
            string sortedStr = str[i];
            std::sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].push_back(str[i]);
        }
        for (auto it = map.begin(); it != map.end(); it++ ) {
            ans.push_back(it->second);
        }
        return ans;
    }
};



//class Solution {
//public:
//    unordered_multimap<string, int> map;
//    unordered_set<string> set;
//    vector<vector<string>> groupAnagrams(vector<string>& str) {
//        map.clear();
//        set.clear();
//        vector<vector<string>> ans;
//        for (int i = 0; i < str.size(); i++) {
//            string sortedStr = str[i];
//            std::sort(sortedStr.begin(), sortedStr.end());
//            map.insert(make_pair(sortedStr, i));
//            set.insert(sortedStr);
//        }
//
//        for (auto it = set.begin(); it != set.end(); it++ ) {
//            auto ret = map.equal_range(*it);
//            vector<string>tempVec;
//            for (auto iter = ret.first; iter != ret.second; ++iter) {
//                tempVec.push_back(str[iter->second]);
//            }
//            ans.push_back(tempVec);
//        }
//        return ans;
//    }
//};

}

#endif /* GroupAnagrams_hpp */
