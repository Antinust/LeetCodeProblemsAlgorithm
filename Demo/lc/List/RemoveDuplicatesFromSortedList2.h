//
//  RemoveDuplicatesFromSortedList2.h
//  Demo
//
//  Created by zcc_imac on 2022/5/1.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef RemoveDuplicatesFromSortedList2_h
#define RemoveDuplicatesFromSortedList2_h
#import "PublicCommon.h"
namespace RemoveDuplicatesFromSortedList2 {

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *prevHead = new ListNode(-101);
        prevHead->next = head;
        ListNode *p = prevHead;
        while (p->next && p->next->next) {
            if (p->next->val == p->next->next->val) {
                int val = p->next->val;
                while (p->next && p->next->val == val) {
                    p->next = p->next->next;
                }
            } else {
                p = p->next;
            }
        }
        return prevHead->next;
    }
};

}

#endif /* RemoveDuplicatesFromSortedList2_h */
