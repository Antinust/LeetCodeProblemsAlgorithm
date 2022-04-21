//
//  BinaryTreeTraversal.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/5.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "BinaryTreeTraversal.h"
#include "InorderTraversal.hpp"
#include "LowestCommonAncestor.hpp"
#include "CourseSchedule.hpp"
#include "CourseSchedulePrintOrder.hpp"
#include "NumIslands.hpp"
#include "ValidBST.hpp"
#include "SymmetricTree.hpp"
#import "BuildTreeFromPreInorder.hpp"
#import "FlattenBTToLinkedList.hpp"
#import "CombinationSum.hpp"
#import "SearchPublicHeader.h"

@interface BinaryTreeTraversal()
{
    CourseSchedule::Solution *_testInstance;
}
@end

@implementation BinaryTreeTraversal

- (instancetype)init {
    self = [super init];
    if (self ) {
        [self testForLC_validBST];
        [self testForLC_SymmetricTree];
        [self testForLC_BuildTreeFromPreInorder];
        [self testForLC_FlattenBTToLinkedList];
        [self testForLC_CombinationSum];
        [self testWordSearch];
    }
    return self;
}

- (void)testWordSearch {
    WordSearch::Solution *sol = new WordSearch::Solution();
//    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> board = {{'a'}};
//    string word = "ABCCED";
    string word = "a";

    sol->exist(board, word);
}

- (void)testForLC_CombinationSum {
    CombinationSum::Solution *sol = new CombinationSum::Solution();
    vector<int> candidates = {2, 3, 7};
    int target = 7;
    sol->combinationSum(candidates, target);
}

- (void)testForLC_FlattenBTToLinkedList {
    FlattenBTToLinkedList::Solution *sol = new FlattenBTToLinkedList::Solution();
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    root->left = left;
    root->right = right;
    
    sol->flatten(root);
}

- (void)testForLC_BuildTreeFromPreInorder {
    vector<int>vec1 = {3,9,20,15,7};
    vector<int>vec2 = {9,3,15,20,7};
    BuildTreeFromPreInorder::Solution *sol = new BuildTreeFromPreInorder::Solution();
    sol->buildTree(vec1, vec2);
}

- (void)testForLC_SymmetricTree {
    SymmetricTree::Solution *sol = new SymmetricTree::Solution();
//    [1,2,2,2,null,2]
    TreeNode *root = new TreeNode(1);
    TreeNode *leftChild = new TreeNode(2);
    TreeNode *rightChild = new TreeNode(2);
    root->left = leftChild;
    root->right = rightChild;
    
    sol->isSymmetric(root);
}

- (void)testForLC_NumIsLands {
                        //    [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
    
   vector<vector<char>> vec = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    
//    vector<vector<char>> vec = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    
//    vector<vector<char>> vec = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};

    //注意下面这个badCase，在最后在set里面找集合个数时，再调用一次findParent()，找到根节点
//    vector<vector<char>> vec = {{'1','0','1','1','1'},{'1','0','1','0','1'},{'1','1','1','0','1'}};
    
    NumIslands::Solution *sol = new NumIslands::Solution();
    sol->numIslands(vec);
}


- (void)testForLC_validBST {
    ValidBST::Solution *sol = new ValidBST::Solution();
    TreeNode *root = new TreeNode(5);
    TreeNode *left = new TreeNode(4);
    TreeNode *right = new TreeNode(6);
    
    root->left = left;
    root->right = right;
    
    TreeNode *leftOfRChild = new TreeNode(3);
    TreeNode *rightOfRChild = new TreeNode(7);
    root->right->left = leftOfRChild;
    root->right->right = rightOfRChild;

    sol->isValidBST(root);
}





- (void)testForLC_Traversal {
    [self testForLC_NumIsLands];
    
//    2
//    [[1,0]]
    
//    _testInstance = new CourseSchedule::Solution();
//    int numCourses = 4;
//    int numCourses = 4;

//    [[1,4],[2,4],[3,1],[3,2]]
//    std::vector<std::vector<int> > v {{1,4},{2,4},{3,1},{3,2}};
    
//    std::vector<std::vector<int> > v {{1,0}};
    
//    std::vector<std::vector<int> > v {{0, 1}};

//    std::vector<std::vector<int> > v {{1,0}, {0, 1}};
//    4
//    std::vector<std::vector<int> > v {{2,3}, {3,2}};

//    std::vector<std::vector<int> > v {{1,0},{2,0},{3,1},{3,2}};
//
//
//    NSLog(@"canFind:%d", _testInstance->canFinish(numCourses, v));
    
}

- (void)testForLC_CourseSchedule {
    CourseSchedulePrintOrder::Solution *sol = new CourseSchedulePrintOrder::Solution();

//    [[1,4],[2,4],[3,1],[3,2]]
//    std::vector<std::vector<int> > v {{1,4},{2,4},{3,1},{3,2}};
    
//    int numCourses = 4;
//    std::vector<std::vector<int> > v {{1,0},{2,0},{3,1},{3,2}};

//    std::vector<std::vector<int> > v {{0, 1}};

//    std::vector<std::vector<int> > v {{1,0}, {0, 1}};
//    4
//    std::vector<std::vector<int> > v {{2,3}, {3,2}};

    int numCourses = 1;
    std::vector<std::vector<int> > v;

//    [[2,3],[3,2]]
    vector<int> vec = sol->findOrder(numCourses, v);
    

    NSLog(@"canFind:%d", vec[0]);
}
@end
