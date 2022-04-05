//
//  TargetSum.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2020/1/18.
//  Copyright © 2020 Zhuo,Chuncai. All rights reserved.
//

#ifndef TargetSum_hpp
#define TargetSum_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;
using std::vector;
using std::map;
using std::tuple;
using std::string;
using std::queue;


namespace TargetSum {
// recursion-ok
class Solution {
public:
    int64_t ways(vector<int>& nums, int64_t index, int64_t target){
        if (index < 0) return 0;
        if (index == 0) {
            //第1个有可能是0，所以+/- 0都是等于0，所以不应该用(target == nums[0]) || (target == -nums[0]) 而应该用下面的
            return (target == nums[0]) + (target == -nums[0]);
        }
        return ways(nums, index -1, target - nums[index]) + ways(nums, index -1, target + nums[index]);
    }

    int64_t findTargetSumWays(vector<int>& nums, int S) {
        return ways(nums, (int64_t)nums.size() - 1, S);
    }
};

}

/*
 208. Implement Trie
 1. 一开始用数组a[26] 连接下一层的a[26] 会导致本来没有连接关系的也会连接在一起；注意是链表、有序的
*/
//class Trie {
//    struct ListNode {
//        ListNode *next[26];
//        char val;
//        ListNode(char v):val(v){
//            for(int i = 0; i < 26; i++) {
//                next[i] = NULL;
//            }
//        }
//    };
//private:
//    map<string,int>_map;
//    ListNode *_head;
//public:
//    /** Initialize your data structure here. */
//    Trie() {
//        _head = new ListNode(0);
//    }
//
//    /** Inse**rts a word into the trie. */
//    void insert(string word) {
//        ListNode *node_ptr = _head;
//        for (int i = 0; i < word.length(); i++) {
//            //不清楚时 停下来 理一下思路 画画
//            if (!node_ptr->next[word.at(i)-'a']) {
//                node_ptr->next[word.at(i)-'a'] = new ListNode(word.at(i));
//            }
//            node_ptr = node_ptr->next[word.at(i)-'a'];
//        }
//        _map.insert(make_pair(word, 1));
//    }
//
//    /** Returns if the word is in the trie. */
//    bool search(string word) {
//        return _map.find(word) != _map.end();
//    }
//
//    /** Returns if there is any word in the trie that starts with the given prefix. */
//    bool startsWith(string prefix) {
//        ListNode *node_ptr = _head;
//        for (int i = 0; i < prefix.length(); i++) {
//            node_ptr = node_ptr->next[prefix.at(i)-'a'];
//            if (!node_ptr) {
//                return false;
//            }
//            if (node_ptr->val != prefix.at(i)) {
//                return false;
//            }
//        }
//        return true;
//    }
//};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//lc_19
/**
 * 两个指针保持n的间接旧可以找到倒数第n个了。注意判断是否有header节点，以及删除第一个元素时的判断
 */
//struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
//
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        if (!head) {
//            return head;
//        }
//        //注意判断是否有header节点
//
//        ListNode *slow = nullptr;
//        ListNode *fast = head;
//        int cnt = 1;
//        while (fast->next) {
//            if (cnt == n) {
//                slow = head;
//            } else if (cnt > n) {
//                slow = slow->next;
//            }
//            fast = fast->next;
//            cnt++;
//        }
//
//        if (!slow) { // 删除第一个元素，slow指针没有来得及++
//            ListNode *dest = head->next;
//            delete head;
//            return dest;
//        }
//
//        ListNode *dest = slow->next;
//        if (dest) {
//            slow->next = dest->next;
//            delete (dest);
//        }
//        return head;
//    }
//};







//class Solution {
//public:
//    int numberOfArithmeticSlices(vector<int>& A) {
//        int length = (int)A.size();
//        if (length < 3) {
//            return 0;
//        }
//
//        int sum = 0;
//        int diff = A[1] - A[0];
//        int count = 2;
//        for (int i=1; i < length - 1; i++) {
//            if (A[i+1] - A[i] == diff) {
//                count++;
//            } else {
//                sum += (1 + (count - 2)) * (count - 2) / 2;
//                diff = A[i+1] - A[i];
//                count = 2;;
//            }
//        }
//        sum += (1 + (count - 2)) * (count - 2) / 2;
//        return sum;
//    }
//};

//lc_343. Integer Break
//class Solution {
//public:
//    int integerBreak(int n) {
//        static int _product[60];
//
//        if (_product[n] != 0) {
//            return _product[n];
//        }
//
//        _product[1] = _product[2] = 1;
//        _product[3] = 2;
//
//        for (int i=4; i <= 58; i++) {
//            int maxProduct = 0;
//
//            for (int j = 1; j <= i / 2; j++) {
//                int first = j > _product[j] ? j : _product[j];
//                int second = i - j > _product[i - j] ? i - j : _product[i - j];
//                int tempProduct = first * second;
//                if (tempProduct > maxProduct) {
//                    maxProduct = tempProduct;
//                }
//            }
//            _product[i] = maxProduct;
////            printf("a[%d] = %d\r\n", i, maxProduct);
//        }
//
//        return _product[n];
//    }
//};

//lc_474
//class Solution {
//public:
//    //
//    void getZeroAndOnes(const std::string &inputStr, int &zeros, int &ones) {
//        int oneCnt = 0;
//        int zeroCnt = 0;
//        for (int i = 0; i < inputStr.size(); i++) {
//            if (inputStr[i] == '0') {
//                zeroCnt++;
//            } else {
//                oneCnt++;
//            }
//        }
//        zeros = zeroCnt;
//        ones = oneCnt;
//    }
//
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        int length = (int)strs.size();
//        int dp[m+1][n+1];
//        memset(dp, 0, sizeof(dp));
//
//        for (int i = 1; i <= length; i++) {
//            int oneCnt = 0;
//            int zeroCnt = 0;
//            getZeroAndOnes(strs[i-1], zeroCnt, oneCnt);
//
//            for (int j = m; j >= zeroCnt; j--) {
//                for (int k = n; k >= oneCnt; k--) {
//                    if (dp[j-zeroCnt][k-oneCnt] + 1 > dp[j][k]) {
//                        dp[j][k] = dp[j-zeroCnt][k-oneCnt] + 1;
//                    }
//                }
//            }
//        }
//        return dp[m][n];
//    }
//};

//lc_322
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        if (amount < 0) {
//            return -1;
//        }
//
//        if (amount == 0) {
//            return 0;
//        }
//        //注意用{}会报错
//        vector<int>dp (amount + 1, amount + 1);
//
//        dp[0] = 0;
//
//        for (int i=1; i <= amount; i++) {
//            //init with a maximum value
//            int min = amount + 1;
//            for (int j=0; j < coins.size(); j++) {
//                if ( coins[j] <= i && dp[i-coins[j]] < min) {
//                    min = dp[i-coins[j]];
//                }
//            }
//            if (min != amount + 1) {
//                dp[i] = min + 1;
//            }
////            printf("dp[%d]=%d\r\n", i, dp[i]);
//        }
//        int result = dp[amount] == amount + 1 ? -1 : dp[amount];
//        return result;
//    }
//};


////lc_198
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        size_t length = nums.size();
//
//        if (length <= 0) {
//            return 0;
//        } else if (length == 1) {
//            return nums[0];
//        } else if (length == 2) {
//            return nums[0] > nums[1] ? nums[0] : nums[1];
//        }
//
//        vector<int> dp(length+1); // length+1 elements with the default value 0
//        dp[0] = nums[0];
//        dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
//
//        for (int i = 2; i < length; i++) {
//            int value_chosen_nth = dp[i-2] + nums[i];
//
//            dp[i] = value_chosen_nth > dp[i-1] ? value_chosen_nth : dp[i-1];
//        }
////        printf("dp[length-1]:%d \r\n", dp[length - 1]);
//        return dp[length-1];
//    }
//};


//lc_213
//class Solution {
//public:
//    int rob_without_circle(vector<int> nums) {
//        size_t length = nums.size();
//
//         if (length <= 0) {
//             return 0;
//         } else if (length == 1) {
//             return nums[0];
//         } else if (length == 2) {
//             return nums[0] > nums[1] ? nums[0] : nums[1];
//         }
//
//         vector<int> dp(length+1); // length+1 elements with the default value 0
//         dp[0] = nums[0];
//         dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
//
//         for (int i = 2; i < length; i++) {
//             int value_chosen_nth = dp[i-2] + nums[i];
//
//             dp[i] = value_chosen_nth > dp[i-1] ? value_chosen_nth : dp[i-1];
//         }
//        return dp[length - 1];
//    }
//
//    int rob(vector<int>& nums) {
//        size_t length = nums.size();
//
//        if (length <= 0) {
//            return 0;
//        } else if (length == 1) {
//            return nums[0];
//        }
//        else if (length == 2) {
//            return nums[0] > nums[1] ? nums[0] : nums[1];
//        } else if (length == 3) {
//            int num1 = nums[0] > nums[1] ? nums[0] : nums[1];
//            int num2 = num1 > nums[2] ? num1 : nums[2];
//            return num2;
//        }
//
//        vector<int> dp(length+1); // length+1 elements with the default value 0
//        dp[0] = nums[0];
//        dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
//        dp[2] = dp[1] > nums[2] ? dp[1] : nums[2];
//
//        for (int i = 3; i < length; i++) {
//            vector<int > vec1;
//            vector<int > vec2;
//            vec1.assign(nums.begin() + 1, nums.begin() + i + 1);
//            vec2.assign(nums.begin() + 2, nums.begin() + i);
//            //通过第0个选或不选 化成了上一题(lc_198)的类型
//            int value_deselect_first = rob_without_circle(vec1);
//            int value_select_first = rob_without_circle(vec2) + nums[0];
//
//            dp[i] = value_select_first > value_deselect_first ? value_select_first : value_deselect_first;
//        }
////        printf("dp[length-1]:%d \r\n", dp[length - 1]);
//        return dp[length-1];
//    }
//};
#endif /* TargetSum_hpp */
