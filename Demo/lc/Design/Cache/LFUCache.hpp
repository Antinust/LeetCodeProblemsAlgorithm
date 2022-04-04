//
//  LFUCache.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/2/28.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LFUCache_hpp
#define LFUCache_hpp

#include <stdio.h>
#include <unordered_map>
#include <map>
#include <sys/time.h>
#include <stdint.h>
#include <time.h>
#include <list>

using namespace std;

/*
 1. 方法一：两个哈希表， map<key, Node*>     map<freq, List<Node*>>freqListMap
            但是在freqListMap中找到最小freq对应的链表时，无法O(1)找到
    故需要一个双向链表，存储
 
 struct Node {
    int freq;
    int val;
    
 }
 */
//class LFUCache2 {
//public:
//    struct Node {
//        int freq;
//        int val;
//        Node(int f, int v):freq(f), val(v) { }
//    };
//    
//    int _cap;
//    unordered_map<int, Node*> keyNodeMap;
//    unordered_map<int, list<Node*>>freqListMap;
//
//    LFUCache2(int capacity) {
//        keyNodeMap.clear();
//        freqListMap.clear();
//        _cap = capacity;
//    }
//    
//    int get(int key) {
//        if (keyNodeMap.count(key)) {
//            return -1;
//        }
//        Node *node = keyNodeMap[key];
//        list<Node*> list = freqListMap[node->freq];
//        list.remove(node);
//        if (list.empty()) {
//            freqListMap.erase(node->freq);
//        }
//        
//        //update freqListMap
//        node->freq += 1;
//        if (freqListMap.count(node->freq)) {
//            freqListMap[node->freq].push_front(node);
//        } else {
//            std::list<Node*> l{node};
//            freqListMap[node->freq] = l;
//        }
//        return node->val;
//    }
//    
//    void put(int key, int value) {
//        if (keyNodeMap.count(key)) {
//            Node *node = keyNodeMap[key];
//            node->val = value;
//            
//            list<Node*> list = freqListMap[node->freq];
//            list.remove(node);
//            if (list.empty()) {
//                freqListMap.erase(node->freq);
//            }
//            
//            //update freqListMap
//            node->freq += 1;
//            if (freqListMap.count(node->freq)) {
//                freqListMap[node->freq].push_front(node);
//            } else {
//                std::list<Node*> l{node};
//                freqListMap[node->freq] = l;
//            }
//        } else {
//            if (freqListMap.size() >= _cap) {
////                freqListMap
//            }
//            
//            Node *node = new Node(1, value);
//            if (freqListMap.count(node->freq)) {
//                freqListMap[node->freq].push_front(node);
//            } else {
//                std::list<Node*> l{node};
//                freqListMap[node->freq] = l;
//            }
//            keyNodeMap[key] = node;
//        }
//    }
//};

class LFUCache {
private:
    struct Node {
        int freq = 0;
        list<pair<int, int>> container;
        Node(int f):freq(f){}
    };
                    // <key, node >
    unordered_map<int, list<Node>::iterator > map;
    unordered_map<int, list<pair<int, int>>::iterator> keyListElemAddrMap;
    list<Node> list;
    int _capacity = 0;
    
public:
    LFUCache(int capacity) {
        _capacity = capacity;
        map.clear();
        list.clear();
        keyListElemAddrMap.clear();
    }
    
    int get(int key) {
        if (_capacity <= 0) {
            return -1;
        }
        
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }
        auto it2 = keyListElemAddrMap.find(key);
        int value = it2->second->second;
        
        // update frequence
        auto itOld = it->second;
        itOld->container.erase(keyListElemAddrMap[key]);
        auto itNew = next(itOld);
        if (itNew != list.end() && itNew->freq == itOld->freq + 1) {
            itNew->container.push_front(make_pair(key, value));
            keyListElemAddrMap[key] = itNew->container.begin();
            map[key] = itNew;
        } else {
            // create new node
            auto it = list.insert(itNew, Node(itOld->freq + 1));
            
            it->container.push_front(make_pair(key, value));
            keyListElemAddrMap[key] = it->container.begin();
            map[key] = it;
        }
        if (itOld->container.empty()) {
            list.erase(itOld);
        }
        
        return value;
    }
    
    void put(int key, int value) {
        if (_capacity <= 0) {
            return;
        }
        
        // not exist insert
        auto it = map.find(key);
        if (it == map.end()) {
            // remove LFU item (eg min freq & longest interval since last access) if reach max capacity
            if (map.size() >= _capacity) {
                map.erase(list.begin()->container.back().first);
                list.begin()->container.pop_back();
            }
            // if list has freq=1 element
            if (list.size() > 0 && list.front().freq == 1) {
                list.front().container.push_front(make_pair(key, value));
                keyListElemAddrMap[key] = list.front().container.begin();
                map[key] = list.begin();
            } else {
                list.push_front(Node(1));
                list.front().container.push_front(make_pair(key, value));
                keyListElemAddrMap[key] = list.front().container.begin();
                map[key] = list.begin();
            }
        } else {
            // remove LFU item (eg min freq & longest interval since last access) only in key not exist in map
//            if (map.size() >= _capacity && list.begin()->container.back().first != key) {
//                map.erase(list.begin()->container.back().first);
//                list.begin()->container.pop_back();
//            }
            
            // if item exist; update value & list
            auto itOld = it->second;
            itOld->container.erase(keyListElemAddrMap[key]);
            auto itNew = next(itOld);
            if (itNew != list.end() && itNew->freq == itOld->freq + 1) {
                itNew->container.push_front(make_pair(key, value));
                keyListElemAddrMap[key] = itNew->container.begin();
                map[key] = itNew;
            } else {
                // create new node
                auto it = list.insert(itNew, Node(itOld->freq + 1));
                
                it->container.push_front(make_pair(key, value));
                keyListElemAddrMap[key] = it->container.begin();
                map[key] = it;
            }
            if (itOld->container.empty()) {
                list.erase(itOld);
            }
        }
        return;
    }
};

#endif
