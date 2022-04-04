//
//  DevideAndConquer.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/22.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "DevideAndConquer.h"
#import "SortAnArray.hpp"
#import "SortList.hpp"

@implementation DevideAndConquer
- (instancetype)init {
    self = [super init];
    if (self) {
        [self testForLC_SortAnArray];
        [self testForLC_SortList];
    }
    return self;
}

//4,2,1,3
- (void)testForLC_SortList {
    SortList::Solution *sol = new SortList::Solution();
//    vector<int>vec = {-2,3,-5};
    ListNode *head = new ListNode(4);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(1);
    ListNode *fourth = new ListNode(3);
    head->next = second;
    second->next = third;
    third->next = fourth;

    sol->sortList(head);
    
}

- (void)testForLC_SortAnArray {
    SortAnArray::Solution *sol = new SortAnArray::Solution();
//    vector<int>vec = {-2,3,-5};
    vector<int> vec = {5,2,3,1};
//    vector<int>vec = {-4,0,7,4,9,-5,-1,0,-7,-1};
    sol->sortArray(vec);
}
@end
