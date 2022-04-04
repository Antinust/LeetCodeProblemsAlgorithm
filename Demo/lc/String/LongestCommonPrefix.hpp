//
//  LongestCommonPrefix.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/3.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LongestCommonPrefix_hpp
#define LongestCommonPrefix_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace longestCommonPrefix {

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string emptyStr = "";
        if (strs.size() == 0) {
            return emptyStr;
        }
        int minCommonLen = INT_MAX;
        int indexOfMinLenStr = 0;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].length() < minCommonLen) {
                minCommonLen = strs[i].length();
                indexOfMinLenStr = i;
            }
        }
        if (minCommonLen == 0) {
            return emptyStr;
        }
        
        int matchedCnt = 0;
        int totalStrsNum = strs.size();
        for (int i = 0; i < minCommonLen; i++) {
            int count = 0;
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != strs[indexOfMinLenStr][i]) {
                    break;
                } else {
                    count++;
                }
            }
            if (count == strs.size()) {
                matchedCnt++;
            } else {
                break;
            }
        }
        //注意substr若只传入一个参数的话，默认只会匹配前面的nPos，不会匹配后面的length
        return matchedCnt == 0 ? emptyStr : strs[indexOfMinLenStr].substr(0, matchedCnt);
    }
};


}


#endif /* LongestCommonPrefix_hpp */
