//
//  FindMedian.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/2/28.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef FindMedian_hpp
#define FindMedian_hpp

#include <stdio.h>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxQueue;   // left
    priority_queue<int, vector<int>, greater<int>> minQueue; // right
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxQueue.empty()) {
            maxQueue.push(num);
        } else if (minQueue.empty()) {
            if (num < maxQueue.top()) {
                minQueue.push(maxQueue.top());
                maxQueue.pop();
                maxQueue.push(num);
            } else {
                minQueue.push(num);
            }
        }
        else {
            /*
             1. l.size == r.size
                    // insert element into left
                    num <= r.min   num -> l
                    num > r.min   r.min -> l &&  num -> r
             2. l.size = r.size + 1
                    // insert element into right
                    num >= l.max  num -> r
                    num < l.max  l.max -> r && num -> l
             */
            if (maxQueue.size() == minQueue.size()) {
                if (num <= minQueue.top()) {
                    maxQueue.push(num);
                } else {
                    maxQueue.push(minQueue.top());
                    minQueue.pop();
                    minQueue.push(num);
                }
            } else {
                if (num >= maxQueue.top()) {
                    minQueue.push(num);
                } else {
                    minQueue.push(maxQueue.top());
                    maxQueue.pop();
                    maxQueue.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if (maxQueue.empty()) {
            return 0;
        } else if (minQueue.empty()) {
            return (double)maxQueue.top();
        } else {
            if (maxQueue.size() > minQueue.size()) {
                return (double)maxQueue.top();
            } else {
                return (maxQueue.top() + minQueue.top() )/ 2.0;
            }
        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
#endif /* FindMedian_hpp */
