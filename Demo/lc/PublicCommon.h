//
//  PublicCommon.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/4.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef PublicCommon_h
#define PublicCommon_h

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif /* PublicCommon_h */
