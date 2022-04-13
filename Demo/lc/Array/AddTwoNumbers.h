//
//  AddTwoNumbers.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/11.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef AddTwoNumbers_h
#define AddTwoNumbers_h
#include "PublicCommon.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

namespace AddTwoNumbers {

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *root = nullptr;
        ListNode *p = nullptr;
        bool hasCarryBit = false;
        while (l1 && l2) {
            int val = l1->val + l2->val + hasCarryBit;
            hasCarryBit = val >= 10;
            val %= 10;
            ListNode *temp = new ListNode(val);
            if (!p) {
                p = temp;
                root = temp;
            } else {
                p->next = temp;
                p = p->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int val = l1->val + hasCarryBit;
            hasCarryBit = val >= 10;
            val %= 10;
            ListNode *temp = new ListNode(val);
            if (!p) {
                p = temp;
                root = temp;
            } else {
                p->next = temp;
                p = p->next;
            }
            l1 = l1->next;
        }
        while (l2) {
            int val = l2->val + hasCarryBit;
            hasCarryBit = val >= 10;
            val %= 10;
            ListNode *temp = new ListNode(val);
            if (!p) {
                p = temp;
                root = temp;
            } else {
                p->next = temp;
                p = p->next;
            }
            l2 = l2->next;
        }
        // 若最后hasCarryBit不为false，说明 还有一个进位为1
        if (hasCarryBit) {
            p->next = new ListNode(1);
        }
        return root;
    }
};

}



#endif /* AddTwoNumbers_h */
