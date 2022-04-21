//
//  NumIslands.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/7.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef NumIslands_hpp
#define NumIslands_hpp

#include <stdio.h>

#include "PublicCommon.h"

namespace NumIslands {

//MARK: - DFS
/*
 1. 每次遍历联通的节点，完了之后置0
 */
//class Solution {
//private:
//    int _rowNum;
//    int _colNum;
//public:
//    bool isIndexValid(int i, int j) {
//        return (i >= 0 && i < _rowNum && j >= 0 && j < _colNum);
//    }
//    void iterateIndex(vector<vector<char>>& vec, int i, int j) {
//        if (isIndexValid(i, i)) {
//            if (vec[i][j] == '1') {
//                dfs(vec, i, j);
//            }
//        }
//    }
//    void dfs(vector<vector<char>>& vec, int i, int j) {
////        if (!isIndexValid(i, j)) {
////            return;
////        }
////        if (vec[i][j] != '1') {
////            return;
////        }
//        // 这一行置0 要放在下个递归index前，否则 下个元素的Left/Top又是自己，就会形成死循环
//        vec[i][j] = '0';
//
//// 递归函数不能放在另外一个函数写，在xcode中调试没有出错，但是在LeetCode网页中提交出错
////    iterateIndex(vec, i - 1, j);
////    iterateIndex(vec, i + 1, j);
////    iterateIndex(vec, i, j - 1);
////    iterateIndex(vec, i, j + 1);
//
//        if (i-1 >= 0 && vec[i-1][j] == '1') {
//            dfs(vec, i - 1, j);
//        }
//        if (i+1 < _rowNum && vec[i+1][j] == '1') {
//            dfs(vec, i + 1, j);
//        }
//        if (j - 1 >= 0 && vec[i][j - 1] == '1') {
//            dfs(vec, i, j - 1);
//        }
//        if (j + 1 < _colNum && vec[i][j + 1] == '1') {
//            dfs(vec, i, j + 1);
//        }
//    }
//    int numIslands(vector<vector<char>>& grid) {
//        if (grid.empty()) {
//            return 0;
//        }
//        int count = 0;
//        _rowNum = (int)grid.size();
//        _colNum = (int)grid[0].size();
//        for (int i = 0; i < _rowNum; i++) {
//            for (int j = 0; j < _colNum; j++) {
//                if (grid[i][j] == '1') {
//                    dfs(grid, i, j);
//                    count++;
//                }
//            }
//        }
//        return count;
//    }
//};


//MARK: - BFS
class Solution {
    struct Node {
        int x = 0;
        int y = 0;
        Node(int i, int j):x(i), y(j) {}
    };
private:
    int _rowNum;
    int _colNum;
public:
    bool isIndexValid(int i, int j) {
        return (i >= 0 && i < _rowNum && j >= 0 && j < _colNum);
    }
//    void iterateIndex(vector<vector<char>>& vec, int i, int j) {
//        if (isIndexValid(i, i)) {
//            if (vec[i][j] == '1') {
//                dfs(vec, i, j);
//            }
//        }
//    }
    void bfs(vector<vector<char>>& vec, int x, int y) {
        queue<Node>que;
        que.push(Node(x, y));
        
        while (!que.empty()) {
            Node node = que.front();
            int i = node.x;
            int j = node.y;
            
            vec[i][j] = '0';
            
            if (i - 1 >= 0 && vec[i-1][j] == '1') {
                que.push(Node(i-1, j));
                // push 之后立马置0，可以剪枝
                vec[i - 1][j] = '0';
            }
            if (j - 1 >= 0 && vec[i][j-1] == '1') {
                que.push(Node(i, j-1));
                vec[i][j-1] = '0';
            }
            if (i + 1 < _rowNum && vec[i+1][j] == '1') {
                que.push(Node(i+1, j));
                vec[i+1][j] = '0';
            }
            if (j + 1 < _colNum && vec[i][j+1] == '1') {
                que.push(Node(i, j+1));
                vec[i][j+1] = '0';
            }
            que.pop();
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int count = 0;
        _rowNum = (int)grid.size();
        _colNum = (int)grid[0].size();
        for (int i = 0; i < _rowNum; i++) {
            for (int j = 0; j < _colNum; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};



//MARK: - Union find
//class Solution {
//private:
//    const static int MAX_LEN = 90002;
//    int nums[MAX_LEN];
//    int fa[MAX_LEN];
//    int rank[MAX_LEN];
//
//public:
//    int find(int x)
//    {
//        return x == fa[x] ? x : (fa[x] = find(fa[x]));
//    }
//
//    void merge(int i, int j)
//    {
//        int x = find(i), y = find(j);    //先找到两个根节点
//        if (rank[x] <= rank[y])
//            fa[x] = y;
//        else
//            fa[y] = x;
//        if (rank[x] == rank[y] && x != y)
//            rank[y]++;                   //如果深度相同且根节点不同，则新的根节点的深度+1
//    }
//
//    int numIslands(vector<vector<char>>& grid) {
//        if (grid.empty()) {
//            return 0;
//        }
//        memset(fa, 0, sizeof(fa));
//        memset(nums, 0, sizeof(nums));
//        memset(rank, 0, sizeof(rank));
//
//        set<int> set;
//        int rowNum = (int)grid.size();
//        int colNum = (int)grid[0].size();
//        for (int i = 0; i < rowNum; i++) {
//            for (int j = 0; j < colNum; j++) {
//                nums[i * colNum + j + 1] = grid[i][j] - '0';
//            }
//        }
//
//        long totalCnt = rowNum * colNum;
//        for (int i = 1; i <= totalCnt; i++) {
//            if (nums[i] == 1) {
//                fa[i] = i;
//            }
//            rank[i] = 1;
//        }
//
//        for (int i = 1; i <= totalCnt; i++) {
//            if (nums[i] == 1) {
//                //merge when left or top is island
//                if (i > colNum && nums[i - colNum] == 1) { // has top & top has island
//                    merge(i, i - colNum);
//                }
//                if (i % colNum != 1 && nums[i - 1] == 1) { // has top & top has island
//                    merge(i, i - 1);
//                }
//            }
//        }
//
//        for (int i = 1; i <= totalCnt; i++) {
//            // 再调用一次find 找到根节点
//            int faVal = find(fa[i]);
//            if (faVal) {
//                set.insert(faVal);
//            }
//        }
//        return set.size();
//    }
//};


}


#endif /* NumIslands_hpp */
