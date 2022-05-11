//
//  LastRemainingInCircle.h
//  Demo
//
//  Created by zcc_imac on 2022/5/11.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LastRemainingInCircle_h
#define LastRemainingInCircle_h

class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = (ans + m) % i;
        }
        return ans;
    }
};


#endif /* LastRemainingInCircle_h */
