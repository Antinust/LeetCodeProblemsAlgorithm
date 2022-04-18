//
//  LCClassification.m
//  Demo
//
//  Created by zcc_imac on 2022/4/5.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "LCClassification.h"
#import "LCSolutionImpl.h"

@implementation LCClassification

- (instancetype)init
{
    self = [super init];
    if (self) {
        [self testForLC_Design];
        
        [self testForLC_string];
        
        [self test_letterComb];
        [self testForLC_rmInvalidParentheses];
        [self testForLC_serialize];
        
        [self test_DP];
        [self testForLC_MeetingRooms2];
    }
    return self;
}

//MARK: - Design
- (void)testForLC_Design {
//    LFU::LFUCache *obj = new LFU::LFUCache(2);
//
//    obj->put(2,1);
//    obj->put(1,1);
//    obj->put(2,3);
//    obj->put(4,1);
//
//    int param_1 = obj->get(1);
//
//    int param_2 = obj->get(2);
//    NSLog(@"param_1:%d param_2:%d", param_1, param_2);
    
    
//    ["LFUCache","put","put","get","put","get","get","put","get","get","get"]
//    [[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]
    
    LFU::LFUCache *obj = new LFU::LFUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    int param_1 = obj->get(1);
    
    obj->put(3, 3);
    int param_2 = obj->get(2);
    int param_3 = obj->get(3);

    obj->put(4, 4);
    int param_4 = obj->get(1);
    int param_5 = obj->get(3);
    int param_6 = obj->get(4);

    obj->put(1,2);

    NSLog(@"param_1:%d param_2:%d param_3:%d param_4:%d", param_1, param_2, param_3, param_4);
    
    
//    LFU::LFUCache *obj = new LFU::LFUCache(2);
//    int param_1 = obj->get(2);
//    obj->put(2,6);
//    int param_2 = obj->get(1);
//    obj->put(1,5);
//    obj->put(1,2);
//    int param_3 = obj->get(1);
//    int param_4 = obj->get(2);
//
//    NSLog(@"param_1:%d param_2:%d param_3:%d param_4:%d", param_1, param_2, param_3, param_4);
    
}


//MARK: - Array
- (void)testForLC_MeetingRooms2 {
    MeetingRooms2::Solution *so = new MeetingRooms2::Solution();
    vector<vector<int>> intervals = {{13, 15}, {1, 13}};
    so->minMeetingRooms(intervals);
}

//MARK: - DFS & BFS
- (void)test_letterComb {
    LetterCombinations::Solution *so = new LetterCombinations::Solution();
    string str = "23";
    so->letterCombinations(str);
}

- (void)testForLC_rmInvalidParentheses {
    RemoveInvalidParentheses::Solution *so = new RemoveInvalidParentheses::Solution();
    string s = "()())()";
    so->removeInvalidParentheses(s);
}

- (void)testForLC_serialize {
//    string str = ",1,2,3,X,X,4,5,6,7,X,X";
    string str = ",1,2,X,X,3,4,X,X,5,X,X";
    SerializeAndDeserializeBinaryTree::Codec *codec = new SerializeAndDeserializeBinaryTree::Codec();
    TreeNode *node = codec->deserialize(str);
    string aStr = codec->serialize(node);
    NSLog(@"str:%s", aStr.c_str());
}


//MARK: - string
- (void)testForLC_string {
    WordBreak::Solution *so = new WordBreak::Solution();
    string str = "aaaaaaa";
    vector<string> wordDict = {"aaaa","aaa"};
    
//    string str = "aebbbbs";
//    vector<string> wordDict = {"a","aeb","ebbbb","s","eb"};

//    vector<string> wordDict = {"apple","pen"};
//    string str = "applepenapple";
    so->wordBreak(str, wordDict);
}

//MARK: - DP
- (void)test_DP {
    [self test_FindNumberOfLIS];
    [self test_equalSubsetSum];
    [self test_PalindromicSubstrings];
}

- (void)test_PalindromicSubstrings {
    PalindromicSubstrings::Solution *so = new PalindromicSubstrings::Solution();
    string s = "abc";
    so->countSubstrings(s);
}


- (void)test_equalSubsetSum {
//    vector<int>vec = {2,2,3,5};
//    vector<int>vec = {1,5,11,5};
    vector<int>vec = {99,1};
    PartitionEqualSubsetSum::Solution *so = new PartitionEqualSubsetSum::Solution();
    so->canPartition(vec);
}


- (void)test_FindNumberOfLIS {
//    vector<int> vec = {1,2,4,3,5,4,7,2};
    vector<int> vec = {1,3,2};
    FindNumberOfLIS::Solution *so = new FindNumberOfLIS::Solution();
    int ret = so->findNumberOfLIS(vec);
    NSLog(@"ret:%d", ret);
}


//MARK: - String


@end
