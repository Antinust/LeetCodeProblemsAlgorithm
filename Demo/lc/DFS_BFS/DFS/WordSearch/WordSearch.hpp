//
//  WordSearch.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/4.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef WordSearch_h
#define WordSearch_h
#include "PublicCommon.h"

namespace WordSearch {
/*
 1. i,j从0,0 开始到m,n 一个used二维数组记录已经选中的元素；若遍历到m，n未找到word则返回false
 
    每次遍历相邻的元素时，需要跳过已经Used的
 Note: when to use Used[i][j] and reset it
 
 badcase: {{'a'}} 'a'
 */

class Solution {
public:
    bool wordExist(vector<vector<char>>& board, int i, int j,
                   string word, int matchedCnt) {
//        if (matchedCnt >= word.length()) {
//            return true;
//        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }
        
        // 这里不需要判断是否越界？ 因为下面已经判断了？ (i >= 0 && i < board.size() && j >= 0 && j < board[0].size())
        if (board[i][j] == word[matchedCnt]) {
            if (word.length()==matchedCnt + 1) {
                return true;
            }
            char tempChar = board[i][j];
            board[i][j] = '.';
            
//            bool leftExist =  wordExist(board, i, j - 1, word, matchedCnt + 1);
//            bool rightExist = wordExist(board, i, j + 1, word, matchedCnt + 1);
//            bool topExist =  wordExist(board, i - 1, j, word, matchedCnt + 1);
//            bool bottomExist =  wordExist(board, i + 1, j, word, matchedCnt + 1);
//            bool leftExist = j < 1 ? false : wordExist(board, i, j - 1, word, matchedCnt + 1);
//            bool rightExist = j >= board[0].size() - 1 ? false : wordExist(board, i, j + 1, word, matchedCnt + 1);
//            bool topExist = i < 1 ? false : wordExist(board, i - 1, j, word, matchedCnt + 1);
//            bool bottomExist = i >= board.size() - 1 ? false :  wordExist(board, i + 1, j, word, matchedCnt + 1);

//            bool exist = (j < 1 ? false : wordExist(board, i, j - 1, word, matchedCnt + 1))
//            || (j >= board[0].size() - 1 ? false : wordExist(board, i, j + 1, word, matchedCnt + 1))
//            || (i < 1 ? false : wordExist(board, i - 1, j, word, matchedCnt + 1))
//            || ( i >= board.size() - 1 ? false :  wordExist(board, i + 1, j, word, matchedCnt + 1));
            
            bool exist = (wordExist(board, i, j - 1, word, matchedCnt + 1))
            || (wordExist(board, i, j + 1, word, matchedCnt + 1))
            || (wordExist(board, i - 1, j, word, matchedCnt + 1))
            || (wordExist(board, i + 1, j, word, matchedCnt + 1));
            
            board[i][j] = tempChar;
            return exist;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //这里使用board[i][j]==word[0]过滤 可以加速？
                if (wordExist(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return  false;
    }
};



//class Solution {
//public:
//    bool wordExist(vector<vector<char>>& board, vector<vector<bool>>& used, int i, int j,
//                   string word, int matchedCnt) {
////        if (matchedCnt >= word.length()) {
////            return true;
////        }
//        // 这里不需要判断是否越界？ 因为下面已经判断了？ (i >= 0 && i < board.size() && j >= 0 && j < board[0].size())
//        if (board[i][j] == word[matchedCnt] && !used[i][j]) {
//            if (word.length()==matchedCnt + 1) {
//                return true;
//            }
//            used[i][j] = true;
//            bool leftExist = j < 1 ? false : !used[i][j-1] && wordExist(board, used, i, j - 1, word, matchedCnt + 1);
//            bool rightExist = j >= board[0].size() - 1 ? false : !used[i][j+1] && wordExist(board, used, i, j + 1, word, matchedCnt + 1);
//            bool topExist = i < 1 ? false : !used[i-1][j] && wordExist(board, used, i - 1, j, word, matchedCnt + 1);
//            bool bottomExist = i >= board.size() - 1 ? false : !used[i+1][j] && wordExist(board, used, i + 1, j, word, matchedCnt + 1);
//            used[i][j] = false;
//            return leftExist | rightExist | topExist | bottomExist;
//        }
//        return false;
//    }
//    bool exist(vector<vector<char>>& board, string word) {
//        int m = board.size();
//        int n = board[0].size();
//        vector<vector<bool>> used(m, vector<bool>(n, 0));
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                //这里使用board[i][j]==word[0]过滤 可以加速？
//                if (board[i][j] == word[0] && wordExist(board, used, i, j, word, 0)) {
//                    return true;
//                }
//            }
//        }
//        return  false;
//    }
//};

}

#endif /* WordSearch_h */
