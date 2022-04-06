//
//  ValidSoduku.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/4.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef ValidSoduku_h
#define ValidSoduku_h
#include "PublicCommon.h"

namespace ValidSoduku {
/*
 1. use hash map to tell if duplicate digit exist in each row or column or 3x3 sub-box
 mind the border/corner case
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            unordered_map<int, int>map;
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.' && ++map[board[i][j]] > 1) {
                    return false;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            unordered_map<int, int>map;
            for (int i = 0; i < m; i++) {
                if (board[i][j] != '.' && ++map[board[i][j]] > 1) {
                    return false;
                }
            }
        }
        
        for (int i = 0; i < m; i += 3) {
            for (int j = 0; j < n; j+=3) {
                unordered_map<int, int>map;
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (board[k][l] != '.' && ++map[board[k][l]] > 1) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

}


#endif /* ValidSoduku_h */
