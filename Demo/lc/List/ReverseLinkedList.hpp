//
//  ReverseLinkedList.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/14.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef ReverseLinkedList_hpp
#define ReverseLinkedList_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace ReverseLinkedList {

class Solution {
    /*
     迭代 把元素插入链表头 即可
     */
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *p = head;
        while (p->next) {
            ListNode *q = p->next;
            p->next = p->next->next;
            q->next = head;
            head = q;
        }
        return head;
    }
};

}


#endif /* ReverseLinkedList_hpp */
