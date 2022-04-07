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
        [self testForLC_string];
        [self test_letterComb];
        [self test_DP];
    }
    return self;
}

//MARK: - DFS & BFS
- (void)test_letterComb {
    LetterCombinations::Solution *so = new LetterCombinations::Solution();
    string str = "23";
    so->letterCombinations(str);
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
