//
//  IntegerReversion.h
//  Demo
//
//  Created by zcc_imac on 2022/5/11.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef IntegerReversion_h
#define IntegerReversion_h
#import "PublicCommon.h"

namespace IntegerReversion {
/*
 要处理的细节很多：
 
 * 需要处理INT_MAX，对应的maxVec，通过%10 /10 求出结果后，要反转一下maxVec
 * 求resVec过程中：
     * 首先需要处理负数，负数的话是resVec.push_back(-(x%10))
     * 需要处理末尾连续的0变成前导0的情况；hasContinuouslyLeadingZero
 * 求ans过程中：
     * 需要比较resVec是否有连续大于maxVec中每一个元素的情况，有的话，直接return0，否则ans+=xxx；需要注意处理=0的情况； 设置isContinuouslyGreater标志位辅助处理
 */

}

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        
        int ans = 0;
        int intMax = INT_MAX;
        vector<int> maxVec;
        while (intMax) {
            maxVec.push_back(intMax % 10);
            intMax /= 10;
        }
        std::reverse(maxVec.begin(), maxVec.end());
        vector<int> minVec(maxVec);
        minVec[maxVec.size() - 1]++;
        
        vector<int> resVec;
        if (x > 0) {
            bool hasLeadingZero = x % 10 == 0;
            while (x) {
                if (!hasLeadingZero) {
                    resVec.push_back(x % 10);
                } else if (x % 10 != 0) {
                    hasLeadingZero = false;
                    resVec.push_back(x % 10);
                }
                // printf("%d ", (x % 10));
                x /= 10;
            }
            // printf("\r\n");
            // std::reverse(resVec.begin(), resVec.end());
            int len = resVec.size();
            if (resVec.size() < maxVec.size()) {
                for (int i = 0; i < len; i++) {
                    ans += resVec[i] * pow(10, len - 1 - i);
                //   printf("ans:%d resVec[%d]=%d\r\n", ans, i, resVec[i]);
                }
            } else {
                bool isContinuouslyGreater = true;
                for (int i = 0; i < len; i++) {
                    // printf("ans:%d resVec[%d]=%d maxVec[i]=%d  isContinuouslyGreater:%d\r\n", ans, i, resVec[i], maxVec[i], isContinuouslyGreater);
                    if (resVec[i] > maxVec[i] && isContinuouslyGreater) {
                        return 0;
                    } else if (resVec[i] < maxVec[i]){
                        isContinuouslyGreater = false;
                    }
                    
                    ans += resVec[i] * pow(10, len - i - 1);
                }
            }
        } else {
            bool hasLeadingZero = x % 10 == 0;
            while (x) {
                if (!hasLeadingZero) {
                    resVec.push_back(-(x % 10));
                } else if (x % 10 != 0) {
                    hasLeadingZero = false;
                    resVec.push_back(-(x % 10));
                }
                // printf("%d ", -(x % 10));
                x /= 10;
            }
            // printf("\r\n");
            // std::reverse(resVec.begin(), resVec.end());
            int len = resVec.size();
            if (resVec.size() < minVec.size()) {
                for (int i = 0; i < len; i++) {
                    ans -= resVec[i] * pow(10, len - 1 - i);
                //   printf("ans:%d resVec[%d]=%d\r\n", ans, i, resVec[i]);
                }
            } else {
                bool isContinuouslyGreater = true;
                for (int i = 0; i < len; i++) {
                    // printf("ans:%d resVec[%d]=%d minVec[i]=%d\r\n", ans, i, resVec[i], minVec[i]);
                    if (resVec[i] > minVec[i] && isContinuouslyGreater) {
                        return 0;
                    } else if (resVec[i] < minVec[i]) {
                        isContinuouslyGreater = false;
                    }
                    ans -= resVec[i] * pow(10, len - i - 1);
                }
            }
        }
        return ans;
    }
};


#endif /* IntegerReversion_h */
