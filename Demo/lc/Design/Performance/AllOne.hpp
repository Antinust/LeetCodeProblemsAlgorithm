//
//  AllOne.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/1.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef AllOne_hpp
#define AllOne_hpp

#include <stdio.h>
#include <string>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <list>

/*
 ["AllOne","inc","inc","inc","inc","inc","dec","dec","getMaxKey","getMinKey"]
 [[],["a"],["b"],["b"],["b"],["b"],["b"],["b"],[],[]]
 
 注意badcase：过一周后重新提交一次
 */

// 1. 容器 插入 元素 是拷贝了一份
// 
using namespace::std;

class AllOne {
private:
    struct Node {
        int val = 0;
        unordered_set<string> container;
        Node(int v):val(v){}
    };
    
    std::string emptyString = "";
    /**
     list + hashMap
     */
    unordered_map<string, list<Node>::iterator > map;
    list<Node> list;
    
public:
    AllOne() {
        map.clear();
        list.clear();
    }
    
    void inc(string key) {
        
        if (map.count(key)) {
            // 若新的level对应的node存在，则必有 next(oldNode, 1)->level = old_level+1; 否则创建新的node
            auto it = map[key];
            auto itNext = next(it);
            
            if (itNext != list.end() && itNext->val == it->val + 1) {
                itNext->container.insert(key);
                map[key] = itNext;
            } else {
                // create new node
                Node node(it->val + 1);
                node.container.insert(key);
                map[key] = list.insert(itNext, node);
            }
            //
            it->container.erase(key);
            if (it->container.size() == 0) {
                list.erase(it);
//                map.erase(key);
            }
        } else {
            if (list.size() > 0 && list.front().val == 1) {
                list.front().container.insert(key);
            } else {
                // create new_node
                Node node(1);
                node.container.insert(key);
                list.push_front(node);
            }
            map[key] = list.begin();
        }
        // operator[]: if key not exist: inserts a new element with that key and default value
    }
    
    void dec(string key) {
        if (map.count(key)) {
            // 若新的level对应的node存在，则必有 next(oldNode, 1)->level = old_level-1; 否则创建新的node
            auto it = map[key];
            auto itPrev = prev(it);
            // move key to newNode
            if (itPrev != list.end() && itPrev->val == it->val - 1) {
                itPrev->container.insert(key);
                map[key] = itPrev;
            } else {
                if (it->val != 1) {
                    // create new node
                    Node node(it->val - 1);
                    node.container.insert(key);
                    map[key] = list.insert(it, node);
                }
            }
            // remove key from oldNode
            it->container.erase(key);
            if (it->val == 1) {
                map.erase(key);
            }
            if (it->container.size() == 0) {
                list.erase(it);
            }
        }
    }
    
    string getMaxKey() {
        if (list.size() == 0 || list.empty()) {
            return emptyString;
        }
        string str = *list.rbegin()->container.begin();
        return str;
        return emptyString;
    }
    
    string getMinKey() {
        if (list.size() == 0 || list.empty()) {
            return emptyString;
        }
        string str = *list.begin()->container.begin();
        return str;
        return emptyString;
    }
};



//MARK: -  to fix me

//typedef struct node {
//    int refCnt;
//    std::list<std::string>::iterator listItemIt;
//} Node;
//
//class AllOne {
//private:
//    std::string emptyString = "";
//    int minLevel = INT_MAX;
//    int maxLevel = INT_MIN;
//
//    std::unordered_map<std::string, Node > keyRefcntAddrMap;
//    std::unordered_map<int, std::list<std::string> > refcntListMap;
//
//public:
//    AllOne() {
//
//    }
//
//    void updateMinAndMaxLevel(int level) {
//        if (level < minLevel) {
//            minLevel = level;
//        }
//        if (level > maxLevel) {
//            maxLevel = level;
//        }
//    }
//
//    void inc(std::string key) {
//        int refcntNew = 1;
//        auto it = keyRefcntAddrMap.find(key);
//        if (it == keyRefcntAddrMap.end()) {
//
//            // find list with refcnt == 1
//            auto refCntListMapIt = refcntListMap.find(1);
//            if (refCntListMapIt == refcntListMap.end()) {
//                // if list with refcnt == 1 does not exist
//                std::list<std::string> keys;
//                keys.push_front(key);
//
//                std::pair<int, std::list<std::string>> pair = std::make_pair(1, keys);
//                refcntListMap.insert(pair);
//
//                Node node = {};
//                node.listItemIt = pair.second.begin();
//                node.refCnt = 1;
//
//                keyRefcntAddrMap.insert(std::make_pair(key, node));
//            } else {
//                // push key into list in front
//                refCntListMapIt->second.push_front(key);
//
//                Node node = {};
//                node.listItemIt = refCntListMapIt->second.begin();
//                node.refCnt = 1;
//
//                keyRefcntAddrMap.insert(std::make_pair(key, node));
//            }
//            updateMinAndMaxLevel(refcntNew);
//        } else {
//            /*
//             find refCnt with key
//             find list with refCnt, remove item from list
//             insert item in list with refCnt + 1
//             refCnt + 1
//             */
//            Node nodeOrigin = it->second;
//            int refCntOrigin = nodeOrigin.refCnt;
//            refcntNew = refCntOrigin + 1;
//
//            auto refCntListMapIt = refcntListMap.find(refCntOrigin);
//            if (refCntListMapIt != refcntListMap.end()) {
//                // if list with refcnt exist, remove item
////MARK: - TODO : below line crash
//                refCntListMapIt->second.erase(nodeOrigin.listItemIt);
//
//                auto refCntListMapItNew = refcntListMap.find(refcntNew);
//                if (refCntListMapItNew == refcntListMap.end()) {
//                    //list with refcntNew not exist
//
//                    std::list<std::string> keys {key};
//                    refcntListMap.insert(std::make_pair(refcntNew, keys));
//
//                    nodeOrigin.listItemIt = keys.begin();
//                    nodeOrigin.refCnt = refcntNew;
//
//                    keyRefcntAddrMap.insert(std::make_pair(key, nodeOrigin));
//                } else {
//                    // exist, push key into list in front
//                    refCntListMapItNew->second.push_front(key);
//
//                    nodeOrigin.listItemIt = refCntListMapItNew->second.begin();
//                    nodeOrigin.refCnt = refcntNew;
//                }
//            }
//            updateMinAndMaxLevel(refcntNew);
//        }
//    }
//
//    void dec(std::string key) {
//        /*
//         find refCnt with key
//         find list with refCnt, remove item from list
//         if refCnt > 1, then insert item in list with refCnt - 1 ; else erase it
//
//         */
//        auto it = keyRefcntAddrMap.find(key);
//        Node nodeOrigin = it->second;
//        int refcntOrigin = nodeOrigin.refCnt;
//        int refcntNew = nodeOrigin.refCnt - 1;
//
//        if (it != keyRefcntAddrMap.end()) {
//            //
//            auto itNew = refcntListMap.find(refcntOrigin);
//
//            itNew->second.erase(nodeOrigin.listItemIt);
//
//            if (refcntOrigin == 1) {
//                keyRefcntAddrMap.erase(it);
//                // 若list中的size=0 需要移除整个list
//                if (itNew->second.size() == 0) {
//                    refcntListMap.erase(itNew);
//                }
//            } else {
//                //
//                if (itNew == refcntListMap.end()) {
//                    //list with refcntNew not exist
//
//                    std::list<std::string> keys {key};
//                    refcntListMap.insert(std::make_pair(refcntNew, keys));
//
//                    nodeOrigin.listItemIt = keys.begin();
//                    nodeOrigin.refCnt = refcntNew;
//                } else {
//                    // exist, push key into list in front
//                    itNew->second.push_front(key);
//
//                    nodeOrigin.listItemIt = itNew->second.begin();
//                    nodeOrigin.refCnt = refcntNew;
//                }
//            }
//        } else {
//            //this case not exist ; ignore
//        }
//        updateMinAndMaxLevel(refcntNew);
//    }
//
//    std::string getMaxKey() {
//        if (maxLevel < 1) {
//            return emptyString;
//        }
//        auto it = refcntListMap.find(maxLevel);
//        if (it == refcntListMap.end()) {
//            return emptyString;
//        } else {
//            return it->second.front();
//        }
//        return emptyString;
//    }
//
//    std::string getMinKey() {
//        if (minLevel < 1) {
//            return emptyString;
//        }
//        auto it = refcntListMap.find(minLevel);
//        if (it == refcntListMap.end()) {
//            return emptyString;
//        } else {
//            return it->second.front();
//        }
//        return emptyString;
//    }
//};

#endif /* AllOne_hpp */
