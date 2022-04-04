//
//  LRUCache.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/17.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LRUCache_hpp
#define LRUCache_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace LRUCache {



/**
lc_146: list + unordered_map
 ["LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put" ,"get","put","put","get","put","put","put","put","put","get","put","put","get"]
 [[10],[10,13],[3,17],[6,11],[10,5],[9,10],[13],[2,19],[2],[3],[5,25],[8],[9,22],[5,5],[1,30],[11],[9,12],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12]]
 
 
 
 ["LRUCache","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put","put" ,"put","put","get"]
 [[10],[10,13],[3,17],[6,11],[10,5],[9,10],[2,19],[5,25],[9,22],[5,5],[9,12],[12,24],[5,18],[7,23],[3,27],[2,12],[2,9],[13,4],[8,18],[1,7],[9,29],[8,21],[6,30],[1,12],[12]]
 
*/
class LRUCache {
private:
    list<pair<int, int>> _cache;
    std::unordered_map<int, list<pair<int, int>>::iterator> _map;
    int _capacity;
public:
    
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto map_iter = _map.find(key);
        if (map_iter == _map.end()) {
            return -1;
        }
        
        auto list_iter = map_iter->second;
        int value = list_iter->second;
        
        //移除当前元素，并插入到链表头
        _cache.erase(list_iter);
        _cache.push_front(make_pair(key, value));
        map_iter->second = _cache.begin();
        return value;
    }
    
    void put(int key, int value) {
        
        auto map_iter = _map.find(key);
        if (map_iter != _map.end()) { //存在相同的Key时，map中不移除，链表中移除Key对应的元素，再把它插入链表头，而不是移除链表尾部(较旧)的元素，
           auto list_iter = map_iter->second;
           //移除当前元素，并插入到链表头
           _cache.erase(list_iter);
           _cache.push_front(make_pair(key, value));
           map_iter->second = _cache.begin();
        } else {
            if (_map.size() >= _capacity) {
                //删除某个元素时：1，map中移除  2，把链表尾部的元素删除(pop_back), 再插入元素到链表头(push_front)
                int key_old = _cache.back().first;
                _map.erase(key_old);
                _cache.pop_back();
            }
            //容量够时直接插入即可
            _cache.push_front(make_pair(key, value));
            //重复的Key存在时 insert 会失败，用[]
            _map[key] = _cache.begin();
        }
    }
};

}

#endif /* LRUCache_hpp */
