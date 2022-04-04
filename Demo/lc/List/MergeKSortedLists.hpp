//
//  MergeKSortedLists.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/13.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MergeKSortedLists_hpp
#define MergeKSortedLists_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace MergeKSortedLists {
/*
 1. 归并排序链表，先分再合；
 
 2. 使用优先队列(小顶堆)，存每个储链表的第一个元素，然后依次从堆中取元素即可；
 参考https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/c-you-xian-dui-lie-liang-liang-he-bing-fen-zhi-he-/
 */

class Solution {
public:
    struct cmp{
        bool operator ()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;// 按照value从小到大排列
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        if (lists.size() < 1) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) { // list[i]需要判空
                pq.push(lists[i]);
            }
        }
        
        ListNode *root = NULL;
        ListNode *p = NULL;
        while (!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();
            if (node->next) {
                pq.push(node->next);
            }
            if (!root) {
                root = node;
                p = node;
            } else {
                p->next = node;
                p = p->next;
            }
        }
        return root;
    }
};

//class Solution {
//public:
//    ListNode* mergeTwoList(ListNode* la, ListNode* lb) {
//        if (!la) {
//            return lb;
//        }
//        if (!lb) {
//            return la;
//        }
//        ListNode *p = la;
//        ListNode *q = lb;
//        ListNode *lc = NULL;
//        ListNode *temp = NULL;
//        ListNode *r = NULL;
//        while (p && q) {
//            if (p->val < q->val) {
//                temp = p;
//                p = p->next;
//            } else {
//                temp = q;
//                q = q->next;
//            }
//            if (!lc) {
//                lc = temp;
//                r = temp;
//            } else {
//                r->next = temp;
//                r = r->next;
//            }
//        }
//        while (p) {
//            r->next = p;
//            r = r->next;
//            p = p->next;
//        }
//        while (q) {
//            r->next = q;
//            r = r->next;
//            q = q->next;
//        }
//        return lc;
//    }
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        if (lists.size() < 1) {
//            return NULL;
//        }
//        if (lists.size() == 1) {
//            return lists[0];
//        }
//        ListNode *root = lists[0];
//        for (int i = 1; i < lists.size(); i++) {
//            root = mergeTwoList(root, lists[i]);
//        }
//        return root;
//    }
//};


//class Solution {
//public:
//    ListNode* mergeTwoList(ListNode* la, ListNode* lb) {
//        if (!la) {
//            return lb;
//        }
//        if (!lb) {
//            return la;
//        }
//        ListNode *p = la;
//        ListNode *q = lb;
//        ListNode *lc = NULL;
//        ListNode *temp = NULL;
//        ListNode *r = NULL;
//        while (p && q) {
//            if (p->val < q->val) {
//                temp = p;
//                p = p->next;
//            } else {
//                temp = q;
//                q = q->next;
//            }
//            if (!lc) {
//                lc = temp;
//                r = temp;
//            } else {
//                r->next = temp;
//                r = r->next;
//            }
//        }
//        while (p) {
//            r->next = p;
//            r = r->next;
//            p = p->next;
//        }
//        while (q) {
//            r->next = q;
//            r = r->next;
//            q = q->next;
//        }
//        return lc;
//    }
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        if (lists.size() < 1) {
//            return NULL;
//        }
//        if (lists.size() == 1) {
//            return lists[0];
//        }
//        ListNode *root = lists[0];
//        for (int i = 1; i < lists.size(); i++) {
//            root = mergeTwoList(root, lists[i]);
//        }
//        return root;
//    }
//};

}

#endif /* MergeKSortedLists_hpp */
