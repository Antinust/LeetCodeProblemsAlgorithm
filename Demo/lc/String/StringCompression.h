//
//  StringCompression.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/29.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef StringCompression_h
#define StringCompression_h
#include "PublicCommon.h"
namespace StringCompression {
class Solution {
public:
    int compress(vector<char>& a) {
        int len = a.size();
        if (len == 1) return len;

        int processedIndex = 0;
    // 向后比较 不容易处理 ["7","7","2","2"]变成["7","2","3"]的badcase
        for (int i = 0; i < len; i++) {
            int repeatedCharLen = 1;
            while (i + 1 < len && a[i] == a[i + 1]) {
                i++;
                repeatedCharLen++;
            }
            if (repeatedCharLen > 1) {
                vector<int> vec;
                while (repeatedCharLen) {
                    vec.push_back(repeatedCharLen % 10 + '0');
                    repeatedCharLen /= 10;
                }
                a[processedIndex++] = a[i];
//                printf("1 processedIndex:%d i=%d a[i]=%c\r\n",processedIndex, i, a[i]);

                for (int j = vec.size() - 1; j >= 0; j-- ) {
                    a[processedIndex++] = vec[j];
//                    printf("2 processedIndex:%d a[%d]=%c\r\n",processedIndex, processedIndex, a[processedIndex]); 这行打印输出会导致数组越界
                }
                
            } else {
                a[processedIndex++] = a[i];
//                printf("3 processedIndex:%d a[%d]=%c\r\n",processedIndex, processedIndex, a[processedIndex]); 这行打印输出会导致数组越界
                
            }
            printf("4 processedIndex:%d\r\n", processedIndex);
        }
        for (int i = 0; i < len; i++) {
            printf(" %c ", a[i]);
        }
        return processedIndex + 1;
    }
};

}

#endif /* StringCompression_h */
