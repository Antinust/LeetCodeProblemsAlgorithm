//
//  TopKFreqency.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/3.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef TopKFreqency_hpp
#define TopKFreqency_hpp

#include <stdio.h>
#include <queue>
#include <vector>
#include <map>

using namespace std;

class Solution3 {
private:
    struct Node {
    public:
        int freq = 0;
        int key = 0;
        Node(int f, int k):key(k), freq(f) {}
        
        bool operator< (const Node& b) const{
            return this->freq < b.freq;
        }
        bool operator> (const Node& b) const {
            return this->freq > b.freq;
        }
    };
    // compare currentNode with parent, if compareFunction return true, keep still, else exchange
    // so the when compareFunction is std::less, it's a maxQueue; when std::greater it's a minQueue
    priority_queue<Node, vector<Node>, less<vector<Node>::value_type>> maxQueue;
    priority_queue<Node, vector<Node>, greater<vector<Node>::value_type>> minQueue;
    map<int, int>map;
    int _kth = 0;
    int _minQueueNum = 0;
    int _maxQueueNum = 0;
public:
    Solution3() {
        map.clear();
    }
    
    void updatePriorityQueue(Node node) {
        //
        if (minQueue.empty() || _maxQueueNum == 0) {
            minQueue.push(node);
        } else if (maxQueue.empty()) {
            // 小于小顶堆的最小值
            if (node < minQueue.top()) {
                maxQueue.push(node);
            } else {
                maxQueue.push(minQueue.top());
                minQueue.pop();
                minQueue.push(node);
            }
        } else if (minQueue.size() < _minQueueNum) {
            // 大于大顶堆的最大值
            if (node > maxQueue.top()) {
                minQueue.push(node);
            } else {
                minQueue.push(maxQueue.top());
                maxQueue.pop();
                maxQueue.push(node);
            }
        } else {
            if (node < minQueue.top()) {
                maxQueue.push(node);
            } else {
                maxQueue.push(minQueue.top());
                minQueue.pop();
                minQueue.push(node);
            }
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        _kth = k;
        _minQueueNum = k;
        
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i])) {
                map[nums[i]] += 1;
            } else {
                map[nums[i]] = 1;
            }
        }
        _maxQueueNum = (int)map.size() - k;
        
        for (std::map<int,int>::iterator it = map.begin(); it != map.end(); it++) {
            updatePriorityQueue(Node(it->second, it->first));
        }
        vector<int> v;
        while (!minQueue.empty()) {
            v.push_back(minQueue.top().key);
            minQueue.pop();
        }
        return v;
    }
};

#endif /* TopKFreqency_hpp */
