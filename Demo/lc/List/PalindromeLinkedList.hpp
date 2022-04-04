//
//  PalindromeLinkedList.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/20.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef PalindromeLinkedList_hpp
#define PalindromeLinkedList_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace PalindromeLinkedList {
/*
 1. 找到中间位置，然后反转链表后半部分 再用快慢指针 比较前后两部分
 
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode *ptr = head;
        int totalCnt = 1;
        while (ptr->next) {
            totalCnt++;
            ptr = ptr->next;
        }
        
        ListNode *mid = head;
        int index = 0;
        int halfTotalCnt = totalCnt / 2;
        // 指向后半部分链表头节点
        while (index < halfTotalCnt) {
            mid = mid->next;
            index++;
        }
        // reverse the second half
        ListNode *p = mid;
        ListNode *q = p;
        ListNode *r = NULL;
        while (p->next) {
            r = p->next;
            p->next = p->next->next;
            r->next = q;
            // q永远指向头节点，r指向当前需插入头节点的节点，p指向r的前一个
            q = r;
        }
        
        index = 0;
        ListNode *s = head;
        ListNode *t = q;
        while (index < halfTotalCnt && s && t) {
            if (s->val != t->val) {
                break;
            }
            s = s->next;
            t = t->next;
            index++;
        }
        return index ==  halfTotalCnt;
    }
};

}

#endif /* PalindromeLinkedList_hpp */
