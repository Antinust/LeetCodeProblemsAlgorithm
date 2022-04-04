//
//  LCList.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/14.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "LCList.h"
#import "IntersectionOfTwoLinkedLists.hpp"
#import "ReverseKGroup.hpp"

@implementation LCList

- (instancetype)init {
    self = [super init];
    if (self) {
        [self testForLC_IntersectionOfTwoLinkedLists];
        [self testForLC_ReverseKGroup];
    }
    return self;
}

- (void)testForLC_ReverseKGroup {
    ReverseKGroup::Solution *sol = new ReverseKGroup::Solution();
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    int k = 2;
    sol->reverseKGroup(node1, k);
}

- (void)testForLC_IntersectionOfTwoLinkedLists {
    IntersectionOfTwoLinkedLists::Solution *sol =
                    new IntersectionOfTwoLinkedLists::Solution();
//    1,2,3,4,5
//    sol->getIntersectionNode(<#ListNode *headA#>, <#ListNode *headB#>)
}


@end
