//
//  MergeTwoSortedLists.h
//  Demo
//
//  Created by zcc_imac on 2022/5/1.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MergeTwoSortedLists_h
#define MergeTwoSortedLists_h

namespace MergeTwoSortedLists {
/*
 1. recursion:
    if (l1->val < l2->val) {
        l1->next = recur(l1->next, l2);
        return l1;
    } else {
         l2->next = recur(l1, l2->next);
         return l2;
    }
 2. iteration:
    把prev指向prevHead可以 解决while循环里面需要先判断prev是否为空的情况，也解决了 把prev初始化 放到while之前带来的代码冗余
 */

// iteration
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        } else {
            ListNode *prevHead = new ListNode(-1);
            ListNode *prev = prevHead; // 把prev指向prevHead可以省略下面的这几行
            /*
             if (l1->val < l2->val) {
                 prev = l1;
                 l1 = l1->next;
             } else {
                 prev = l2;
                 l2 = l2->next;
             }
             */
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    prev->next = l1;
                    l1 = l1->next;
                } else {
                    prev->next = l2;
                    l2 = l2->next;
                }
                prev = prev->next;
            }
            prev->next = l1 ? l1 : l2;
            return prevHead->next;
        }
    }
};


// recursion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

}


#endif /* MergeTwoSortedLists_h */
