//
//  ReverseKGroup.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/29.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef ReverseKGroup_hpp
#define ReverseKGroup_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace ReverseKGroup {
/*
 细节很多 注意处理：
 0、在reverse前需要保存endNode->next，因为reverse时会丢掉
 1、翻转之后之前的start变成了end
 2、翻转之后需要把链头赋值给 之前的链尾，之前的链尾可以通过startNode或得(在循环末尾赋值，不要在previous->next = tempRoot前赋值)
 
 */

class Solution {
public:
    ListNode *reverseList(ListNode *head, int k) {
        if (!head) {
            return head;
        }
        ListNode *p = head;
        ListNode *q = head;
        ListNode *r = q->next;
        while (--k > 0 && q->next) {
            r = q->next;
            q->next = q->next->next;
            r->next = p;
            p = r;
        }
        return p;
    }
    
    ListNode * reverseKGroup(ListNode * node, int k) {
        if (!node || k == 1) {
            return node;
        }
        ListNode *startNode = node;
        ListNode *endNode = node;
        ListNode *root = NULL;
        ListNode *previousEnd = startNode;
        
        int count = 0;
        while (endNode) {
            count = 0;
            while (endNode && ++count < k) {
                endNode = endNode->next;
            }
            if (endNode) {
                //在reverse前需要保存endNode->next，因为reverse时会丢掉
                ListNode *tempStart = startNode;
                startNode = endNode->next;
                
                endNode = endNode->next;
                count = 0;
                ListNode *tempRoot = reverseList(tempStart, k); // 返回翻转后的链头 要赋值给上一个的链尾
                if (!root) {
                    root = tempRoot;
                } else {
                    previousEnd->next = tempRoot;
                }
                previousEnd = tempStart; // 翻转之后 之前的start变成了end
            }
        }
        return root;
    }
};

}


#endif /* ReverseKGroup_hpp */
