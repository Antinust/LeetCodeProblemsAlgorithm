//
//  OperationComplexityO1.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/2/12.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef OperationComplexityO1_hpp
#define OperationComplexityO1_hpp

#include <stdio.h>
#include <unordered_map>
#include <vector>

#include <unordered_set>
class RandomizedSet {
private:
    std::unordered_map<int, int> mymap;
    std::vector<int> myvec;
    int index;
public:
    RandomizedSet() {
        index = 0;
        mymap.clear();
        myvec.clear();
    }
    
    bool insert(int val) {
        std::pair<std::unordered_map<int, int>::const_iterator, bool>pair = mymap.insert(std::make_pair(val, index));
        if (pair.second) {
//            Vector通过下标访问，只能修改已经存在的元素，无法通过这种方式新加元素
//            myvec[index] = val;
            myvec.insert(myvec.end(), val);
            index++;
        }
        return pair.second;
    }
    
    bool remove(int val) {

        std::unordered_map<int, int>::const_iterator got = mymap.find(val);
        if (got == mymap.end()) {
            return false;
        }
        int index_to_del = got->second;
        // exchange element to delete with last one
        int val_last = myvec[index-1];
        myvec[index_to_del] = val_last;
        // myvec[index - 1] = val;
        myvec.pop_back();
        index--;

        mymap[val_last] = index_to_del;
        mymap.erase(got);
        
        return true;
    }
    
    int getRandom() {
        int rand_index = rand() % index;
        return myvec[rand_index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

#endif /* OperationComplexityO1_hpp */
