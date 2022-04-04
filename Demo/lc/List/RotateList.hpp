//
//  RotateList.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/13.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef RotateList_hpp
#define RotateList_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace RotateList {
/*
 1. 把链尾和链首连接起来，遍历n-k-1次 找到新的根节点的前一个节点(nodeBeforeRoot)，返回nodeBeforeRoot->next，
 然后nodeBeforeRoot->next置空
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        int totalCnt = 1;
        ListNode *p = head;
        while (p->next) {
            p = p->next;
            totalCnt++;
        }
        k = k % totalCnt;
        p->next = head;
        int iterateCnt = totalCnt - k -1;
        ListNode *nodeBeforeRoot = head;
        while (iterateCnt-- > 0) {
            nodeBeforeRoot = nodeBeforeRoot->next;
        }
        ListNode *root = nodeBeforeRoot->next;
        nodeBeforeRoot->next = NULL;
        return root;
    }
};

}

#endif /* RotateList_hpp */
