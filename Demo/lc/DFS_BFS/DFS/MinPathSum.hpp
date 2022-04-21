//
//  MinPathSum.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/11.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MinPathSum_hpp
#define MinPathSum_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace MinPathSum {

/*
 用dfs递归可以解决，看下别人是否有更 简便高效的方法
 
 */
class Solution {
public:
    const static int INVALID_VALUE = 100000;
    const static int MAX_LENGTH = 204;
    int sum[MAX_LENGTH][MAX_LENGTH];
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size() || j >= grid[0].size()) {
            return INVALID_VALUE;
        }
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            sum[i][j] = grid[i][j];
            return grid[i][j];
        }
        if (sum[i][j] != INVALID_VALUE && sum[i][j] != 0) {
            return sum[i][j];
        }
        sum[i + 1][j] = dfs(grid, i + 1, j);
        sum[i][j + 1] = dfs(grid, i, j + 1);
        sum[i][j] = std::min(sum[i + 1][j], sum[i][j + 1]) + grid[i][j];
        return sum[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(sum, 0, sizeof(sum));
        
        for (int j = 0; j < grid[0].size(); j++) {
            sum[grid.size()][j] = INVALID_VALUE;
        }
        
        for (int i = 0; i < grid.size(); i++) {
            sum[i][grid[0].size()] = INVALID_VALUE;
        }
        dfs(grid, 0, 0);
        return sum[0][0];
    }
};

}

#endif /* MinPathSum_hpp */
