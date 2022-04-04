//
//  SortList.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/22.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SortList_hpp
#define SortList_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace SortList {
/*
 1. 递归+快慢指针：通过快慢指针找到链表的中间节点，再把链表从中间节点切断；递归处理左右两个链表；再把两个有序链表 合并成一个有序的链表
    递归退出条件：链表只有一个节点
 
 */
class Solution {
public:
    ListNode* mergeSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        if (!head->next->next) {
            if (head->val > head->next->val) {
                std::swap(head->val, head->next->val);
            }
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        // 注意判断fast->next不为空时，最好先判断fast不为空
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *secondPartHead = mergeSortList(slow->next);
        slow->next = NULL;
        ListNode *fstPartHead = mergeSortList(head);
        
        ListNode* tempHead = NULL;
        ListNode* p = NULL;
        ListNode* tail = NULL;
        // merge
        while (secondPartHead && fstPartHead) {
            if (secondPartHead->val < fstPartHead->val) {
                if (!p) {
                    p = secondPartHead;
                } else {
                    p->next = secondPartHead;
                    p = p->next;
                }
                secondPartHead = secondPartHead->next;
            } else {
                if (!p) {
                    p = fstPartHead;
                } else {
                    p->next = fstPartHead;
                    p = p->next;
                }
                fstPartHead = fstPartHead->next;
            }
            if (!tempHead) {
                tempHead = p;
            }
            if (!p->next) {
                tail = p;
            }
        }
        p = tail;
        while (secondPartHead) {
            p->next = secondPartHead;
            p = p->next;
            secondPartHead = secondPartHead->next;
        }
        while (fstPartHead) {
            p->next = fstPartHead;
            p = p->next;
            fstPartHead = fstPartHead->next;
        }
        return tempHead;
    }
    
    ListNode* sortList(ListNode* head) {
        return mergeSortList(head);
    }
};

}

#endif /* SortList_hpp */
