//
//  LFU.h
//  Demo
//
//  Created by zcc_imac on 2022/4/18.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LFU_h
#define LFU_h
#import "PublicCommon.h"

namespace LFU {

class LFUCache {
public:
    struct Node {
        // key, value, frequency的顺序要 一一对应，不然容易出错
        int key = 0;
        int val = 0;
        int freq = 0;
        Node(int k, int v, int f): key(k), val(v), freq(f) { }
        string toString() {
            return " k:" + std::to_string(key) + " v:" + std::to_string(val) + " freq:" + std::to_string(freq) + " ";
        }
    };
    
    int _cap = 0;
    int _minFreq = 0; // freqListMap中增加freq时不用管，删除freq时判断当前的freq是否为minFreq即可
    unordered_map<int, list<Node>::iterator> keyNodeMap;  // store key  Node address
    unordered_map<int, list<Node> > freqListMap;  // store frequency, List<node>;


    int get(int key) {
//        printf("get_key :%d\r\n", key);
        if (_cap <= 0) {
            return -1;
        }
        if (keyNodeMap.count(key) == 0) {
            return -1;
        }
        
        auto keyNodeMapIt = keyNodeMap.find(key);
        if (keyNodeMapIt == keyNodeMap.end()) {
            printf("xx get_key :%d\r\n", key);
        }
        int val = keyNodeMapIt->second->val;
        int freq = keyNodeMapIt->second->freq;
        keyNodeMapIt->second->freq++;
        
        // increase freq :
        auto freqListMapIt = freqListMap.find(freq);
        if (freqListMapIt == freqListMap.end()) {
            printf("xxx get_key :%d\r\n", key);
        }

        freqListMapIt->second.erase(keyNodeMapIt->second);
        if (freqListMapIt->second.empty()) {
            freqListMap.erase(freq);
            if (_minFreq == freq) {
                _minFreq++;
            }
        }
        
        // freqListMap[freq + 1].push_front(*keyNodeMapIt->second);
        freqListMap[freq + 1].push_front( Node(key, val, freq + 1) );
        keyNodeMap[key] = freqListMap[freq + 1].begin();
        
        for (auto it = keyNodeMap.begin(); it != keyNodeMap.end(); it++) {
            printf("get  keyNodeMap key:%d value:%s\r\n", it->first, it->second->toString().c_str());
        }
        for (auto it = freqListMap.begin(); it != freqListMap.end(); it++) {
            printf("get  freqListMap key:%d ", it->first);
            for (auto listIt = it->second.begin(); listIt != it->second.end(); listIt++) {
                printf("  value:%s\t ", listIt->toString().c_str());
            }
            printf("\r\n");
        }
        printf("\r\n");


        return val;
    }




    void put(int key, int value) {
//        printf("put_key: %d val:%d\r\n", key, value);

        if (_cap <= 0) {
            return ;
        }

        if (keyNodeMap.count(key)) {
            
            auto keyNodeMapIt = keyNodeMap.find(key);
            keyNodeMapIt->second->val = value;
            int freq = keyNodeMapIt->second->freq;
            keyNodeMapIt->second->freq++;
            
            // increase freq :
            auto freqListMapIt = freqListMap.find(freq);
            freqListMapIt->second.erase(keyNodeMapIt->second);
            if (freqListMapIt->second.empty()) {
                freqListMap.erase(freq);
                if (_minFreq == freq) {
                    _minFreq++;
                }
            }
            
            
            // freqListMap[freq + 1].push_front(*keyNodeMapIt->second);
            freqListMap[freq + 1].push_front(Node(key, value, freq + 1));
            keyNodeMap[key] = freqListMap[freq + 1].begin();
            
        } else {
            if (keyNodeMap.size() >= _cap) {
                Node node = freqListMap[_minFreq].back();
                keyNodeMap.erase(node.key);
                freqListMap[_minFreq].pop_back();
                if (freqListMap[_minFreq].empty()) {
                    freqListMap.erase(_minFreq);
                }
            }
            freqListMap[1].push_front(Node(key, value, 1));
            keyNodeMap[key] = freqListMap[1].begin();
        _minFreq = 1;
        }
        for (auto it = keyNodeMap.begin(); it != keyNodeMap.end(); it++) {
            printf("put  keyNodeMap key:%d value:%s\r\n", it->first, it->second->toString().c_str());
        }
        for (auto it = freqListMap.begin(); it != freqListMap.end(); it++) {
            printf("put  freqListMap key:%d ", it->first);
            for (auto listIt = it->second.begin(); listIt != it->second.end(); listIt++) {
                printf("  value:%s\t ", listIt->toString().c_str());
            }
            printf("\r\n");
        }
        printf("\r\n");
    }


    LFUCache(int capacity) {
        _cap = capacity;
        keyNodeMap.clear();
        freqListMap.clear();
    }
};



//class LFUCache {
//public:
//    struct Node {
//        int freq = 0;
//        list<pair<int, int>> container;
//        Node(int f):freq(f) { }
//    };
//    int _cap = 0;
//    list<Node *> l;
//    unordered_map<int, list<pair<int, int>>::iterator> keyPairMap;  // store key  pair(list element) address
//    unordered_map<int, list<Node*>::iterator > keyNodeMap;  // store key, node address
//
//    int get(int key) {
//        printf("get_key:%d\r\n", key);
//        if (_cap <= 0) {
//            return -1;
//        }
//        auto keyNodeMapIt = keyNodeMap.find(key);
//        if (keyNodeMapIt == keyNodeMap.end()) {
//            return -1;
//        }
//        Node* node = *(keyNodeMapIt->second);
//        auto keyPairMapIt = keyPairMap.find(key);
//        node->container.erase(keyPairMapIt->second);
//        int value = keyPairMapIt->second->second;
//
//        auto nodeListItNext = std::next(keyNodeMapIt->second);
//        if (nodeListItNext != l.end() && (*nodeListItNext)->freq == node->freq + 1) {
//            (*nodeListItNext)->container.push_front(*(keyPairMapIt->second));
//            if (node->container.empty()) {
//                l.erase(keyNodeMapIt->second);
//            }
//            keyPairMap[key] = (*nodeListItNext)->container.begin();
//            keyNodeMap[key] = nodeListItNext;
//        } else {
//            Node *aNode = new Node(node->freq + 1);
//            aNode->container.push_back(*(keyPairMapIt->second));
//
//            keyPairMap[key] = aNode->container.begin();
//            keyNodeMap[key] = l.insert(next(keyNodeMapIt->second), aNode);
//        }
//        printf("get_key2:%d\r\n", key);
//
//        return value;
//    }
//
//    void put(int key, int value) {
//        printf("put_key:%d val:%d\r\n", key, value);
//
//        if (_cap <= 0) {
//            return ;
//        }
//
//        auto keyNodeMapIt = keyNodeMap.find(key);
//        if (keyNodeMapIt != keyNodeMap.end()) {
//
//            Node* node = *(keyNodeMapIt->second);
//
//            auto keyPairMapIt = keyPairMap.find(key);
//            node->container.erase(keyPairMapIt->second);
//            keyPairMapIt->second->second = value;
//
//            auto nodeListItNext = std::next(keyNodeMapIt->second);
//            if (nodeListItNext != l.end() && (*nodeListItNext)->freq == node->freq + 1) {
//                (*nodeListItNext)->container.push_front(*keyPairMapIt->second);
//                if (node->container.empty()) {
//                    l.erase(keyNodeMapIt->second);
//                }
//                keyPairMap[key] = (*nodeListItNext)->container.begin();
//                keyNodeMap[key] = nodeListItNext;
//            } else {
//                Node *aNode = new Node(node->freq + 1);
//                aNode->container.push_back(*keyPairMapIt->second);
//
//                keyPairMap[key] = aNode->container.begin();
//                keyNodeMap[key] = l.insert(next(keyNodeMapIt->second), aNode);
//            }
//
//        } else {
//            if (keyPairMap.size() >= _cap) { // remove lfu
//                Node *node = l.front();
//                int keyToRemove = node->container.back().first;
//                node->container.pop_back();
//                if (node->container.empty()) {
//                    l.pop_front();
//                }
//                keyPairMap.erase(keyToRemove);
//                keyNodeMap.erase(keyToRemove);
//            }
//            // handle freq=1
//            if (!l.empty() && l.front()->freq == 1) {
//                l.front()->container.push_front(make_pair(key, value));
//                keyPairMap[key] = l.front()->container.begin();
//                keyNodeMap[key] = l.begin();
//            } else { // new Node
//                Node *aNode = new Node(1);
//                aNode->container.push_back(make_pair(key, value));
//
//                keyPairMap[key] = aNode->container.begin();
//                l.push_front(aNode);
//                keyNodeMap[key] = l.begin();
//            }
//
//        }
//        printf("put_key 2:%d val:%d\r\n", key, value);
//
//    }
//
//    LFUCache(int capacity) {
//        _cap = capacity;
//        // map.clear();
//        // keyNodeMap.clear();
//    }
//};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



}


#endif /* LFU_h */
