//
//  LinkedListCycle.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/12.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LinkedListCycle_hpp
#define LinkedListCycle_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace LinkedListCycle {
/*
 1. 根据floyd判圈法： 设置fast&slow指针在同一起点，fast+=2 slow++，若链表中存在环的话，则必定在某个节点fast会重新遇上slow
 2. 在当slow处于圆环入口处时，设当前fast距slow的距离为c，圆环长度为b，则必有(0< c < b)，若c=0||b则表示刚入圆环时已经相遇；
 因为fast在圆环内 每次追赶slow一次，经过b-c次后，fast与slow必定第一次相遇，此时slow必定没有走完一圈
 
 3. 当slow走了s步时，进入环内与slow相遇时
 f = 2s = s + nb
 => s= nb
 
 4. 当slow处于圆环入口处时，必有a+nb，当slow第一次与fast相遇时，已经走了nb/s步, slow指针再走a步，必定重新回到入口处，若此时再添加第三个指针third，同时与slow同速度移动，则经过a步后，重新相遇入口处
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        slow = slow->next;
        fast = fast->next->next;
        while (fast && fast->next && fast != slow) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!fast || !fast->next) {
            return false;
        }
        return true;
    }
};

}
#endif /* LinkedListCycle_hpp */
