//
//  IntersectionOfTwoLinkedLists.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/14.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef IntersectionOfTwoLinkedLists_hpp
#define IntersectionOfTwoLinkedLists_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace IntersectionOfTwoLinkedLists {
/*
 1. 双指针，设链表A的长度为a，链表B的长度为B，相交部分的长度为c，指针pa,pb 分别遍历链表AB、BA
    若链表A、B存在相交，则pa和pb必会在入口相遇
    pa所走长度= a + (b - c)
    pb所走长度= b + (a - c)

 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *pa = headA;
        ListNode *pb = headB;
        
        int paReachListEndCnt = 0;
        int pbReachListEndCnt = 0;

        while (pb != pa) {
            while (pa && pb && pa != pb) {
                pa = pa->next;
                pb = pb->next;
            }
            if (!pb) {
                if (++pbReachListEndCnt > 1) {
                    break;
                }
                pb = headA;
            }
            if (!pa) {
                if (++paReachListEndCnt > 1) {
                    break;
                }
                pa = headB;
            }
        }
        return pb != NULL ? pb : NULL;
    }
};

}

//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//
//        ListNode *pa = headA;
//        ListNode *pb = headB;
//
//        while (pa && pb) {
//            pa = pa->next;
//            pb = pb->next;
//        }
//
//        if (!pa) {
//            pa = headB;
//            while (pa && pb) {
//                pa = pa->next;
//                pb = pb->next;
//            }
//            if (!pb) {
//                pb = headA;
//            }
//            while (pa && pb && pb != pa) {
//                pa = pa->next;
//                pb = pb->next;
//            }
//        }
//
//        if (!pb) {
//            pb = headA;
//            while (pa && pb) {
//                pa = pa->next;
//                pb = pb->next;
//            }
//            if (!pa) {
//                pa = headB;
//            }
//            while (pa && pb && pb != pa) {
//                pa = pa->next;
//                pb = pb->next;
//            }
//        }
//        return pb != NULL ? pb : NULL;
//    }
//};


#endif /* IntersectionOfTwoLinkedLists_hpp */
