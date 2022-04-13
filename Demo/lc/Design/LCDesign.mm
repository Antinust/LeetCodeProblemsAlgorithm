//
//  LCDesign.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/3.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "LCDesign.h"
#include "MinStack.hpp"
#include "KthLargest.hpp"
//#include "Solution.hpp"
#include "SlidingWindowMaximum.hpp"
#include "EvalRPN.hpp"
#include "LargestRectangleInHistogram.hpp"
#include "TrappingRainWater.hpp"
#include "TargetSum.hpp"
#include "MaximalSquare.hpp"
#include "ImplementTrie.hpp"

@implementation LCDesign

- (instancetype)init {
    self = [super init];
    if (self) {
        [self testForAll];
    }
    return self;
}

//{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}}
//{{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}}
- (void)testForLC_MaximalSquare {
    MaximalSquare::Solution *sol = new MaximalSquare::Solution();
//    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    
    vector<vector<char>> matrix = {{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
    
    sol->maximalSquare(matrix);
}

- (void)testForLC_MaxRectangle {
    LargestRectangleInHistogram::Solution *sol = new LargestRectangleInHistogram::Solution();
    vector<int>vec = {2,1,5,6,2,3};
    sol->largestRectangleArea(vec);
}

//MARK: - LRU
/*
["LRUCache","put","put","put","put","get","get","get","get","put","get","get","get","get","get"]
[[3],[1,1],[2,2],[3,3],[4,4],[4],[3],[2],[1],[5,5],[1],[2],[3],[4],[5]]
- (void)testForLC_LRU {
     ["LRUCache","put","put","put","put","get","get"]
     [[2],[2,1],[1,1],[2,3],[4,1],[1],[2]]
    
//    LRUCache* cache = new LRUCache(3);
//    cache->put(1, 1);
//    cache->put(2, 2);    //
//    cache->put(3, 3);
//    cache->put(4, 4);
//
//    NSLog(@"get(4)_ret=%d", cache->get(4));
//    NSLog(@"get(3)_ret=%d", cache->get(3));
//    NSLog(@"get(2)_ret=%d", cache->get(2));
//    NSLog(@"get(1)_ret=%d", cache->get(1));
//
//    cache->put(5, 5);
//
//    NSLog(@"get(1)_ret=%d", cache->get(1));
//    NSLog(@"get(2)_ret=%d", cache->get(2));
//    NSLog(@"get(3)_ret=%d", cache->get(3));
//    NSLog(@"get(4)_ret=%d", cache->get(4));
//    NSLog(@"get(5)_ret=%d", cache->get(5));

     ["LRUCache","put","put","put","put","get","get"]
     [[2],[2,1],[1,1],[2,3],[4,1],[1],[2]]
//    LRUCache* cache = new LRUCache(2);
//    cache->put(2, 1);    //
//    cache->put(1, 1);
//    cache->put(2, 3);    //
//    cache->put(4, 1);    //
//
//    NSLog(@"get(1)_ret=%d", cache->get(1));
//    NSLog(@"get(2)_ret=%d", cache->get(2));
}
*/

//MARK: - minimax
- (void)testForminimax {
    Solution4 *sol = new Solution4();
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    sol->maxSlidingWindow(nums, k);
    
}

- (void)testForTopKFreq {
    int k = 2;
//    vector<int> nums = {4,1,-1,2,-1,2,3};
//    vector<int> nums = {1,1,1,2,2,2,3,3,3};

//    vector<int> nums = {5,2,5,3,5,3,1,1,3};
//
//
//    Solution *sol = new Solution();
//
//    vector<int>vec = sol->topKFrequent(nums, k);
//    NSLog(@"vec_beg");
//    for (int i = 0; i < vec.size(); i++) {
//        printf(" %d ", vec[i]);
//    }
//    NSLog(@"vec_end");
}


- (void)testForLC_rpn {
    vector<string> tokens = {"4","13","5","/","+"};
//    vector<string> tokens = {"2","1","+","3","*"};
    EvalRPN::Solution *sol = new EvalRPN::Solution();
    sol->evalRPN(tokens);
}


- (void)testForLC_trapRain {
    TrappingRainWater::Solution *sol = new TrappingRainWater::Solution();
    vector<int> vec = {4,2,0,3,2,5};
    sol->trap(vec);
}

- (void)test_implementTrie {
    ImplementTrie::Trie *obj = new ImplementTrie::Trie();
    
    obj->insert("apple");
    bool ret1 = obj->search("apple");
    bool ret2 = obj->search("app");
    bool ret3 = obj->startsWith("app");
    obj->insert("app");
    bool ret4 = obj->search("app");
    
//    obj->insert("a");
//    bool ret2 = obj->search("a");
//    bool ret3 = obj->startsWith("a");
//    bool ret4 = obj->search("a");
//
//    obj->insert("app");
//    bool ret1 = obj->search("ap");


    NSLog(@"ret1:%d ret2:%d ret3:%d ret4:%d \r\n", ret1, ret2, ret3, ret4);
}

- (void)testForAll {
    [self test_implementTrie];

//    [self testForTopKFreq];
//
//    [self testForLC_KthLargest];
    
    [self testForLC_MaxRectangle];
    
    [self testForLC_trapRain];
    
    [self testForLC_MaximalSquare];
}

- (void)testForLC_KthLargest {
    // design
    //["KthLargest","add","add","add","add","add"]
    //[[3,],[3],[5],[10],[9],[4]]
//    vector<int> vec = {4,5,8,2};
//    int kth = 3;
//    KthLargest *obj = new KthLargest(kth, vec);
//
//    obj->add(3);
//    obj->add(5);
//    obj->add(10);
//    obj->add(9);
//    obj->add(4);
    
    
//    ["KthLargest","add","add","add","add","add"]
//    [[1,[]],[-3],[-2],[-4],[0],[4]]
    
    vector<int> vec = {};
    int kth = 1;
    KthLargest *obj = new KthLargest(kth, vec);
    
    obj->add(-3);
    obj->add(-2);
    obj->add(-4);
    obj->add(0);
    obj->add(4);
    
}


- (void)testForLC_MinStack {
    // design
    MinStack *obj = new MinStack();
    
//    ["MinStack","push","push","push","top","pop","getMin",   "pop","getMin","pop","push","top","getMin"]
//    [[],[46],[46],[47],[],[],[],[],[],[],[47],[],[]]
    
    obj->push(46);
    obj->push(46);
    obj->push(47);

    int param_1 = obj->top();
    obj->pop();
    int param_2 = obj->getMin();

    
    obj->pop();
    int param_3 = obj->getMin();
    obj->pop();
    obj->push(47);
    int param_4 = obj->top();
    int param_5 = obj->getMin();
    NSLog(@"param_1:%d param_2:%d param_3:%d param_4:%d param_5:%d ", param_1, param_2, param_3, param_4, param_5);
}


@end
