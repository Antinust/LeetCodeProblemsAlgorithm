//
//  RotateImage.h
//  Demo
//
//  Created by zcc_imac on 2022/4/5.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef RotateImage_h
#define RotateImage_h

#import "PublicCommon.h"

namespace RotateImage {

/*
 1. 先上下flip 再沿对角线翻转
 
 */
class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                swap(a[i][j], a[n - i - 1][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(a[i][j], a[j][i]);
            }
        }
    }
};

}

#endif /* RotateImage_h */
