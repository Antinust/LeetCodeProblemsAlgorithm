//
//  ValidParentheses.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/21.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef ValidParentheses_hpp
#define ValidParentheses_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace ValidParentheses {
//"(])"
class Solution {
public:
    bool isPushCharacter(string s) {
        if (s.compare("(") == 0
            || s.compare("{") == 0
            || s.compare("[") == 0) {
            return true;
        }
        return false;
    }
    bool isPopCharacter(string s) {
        if (s.compare(")") == 0
            || s.compare("}") == 0
            || s.compare("]") == 0) {
            return true;
        }
        return false;
    }
    bool isTwoCharacterMatch(string s, string t) {
        if ((s.compare("(") == 0 && t.compare(")") == 0)
            || (s.compare("{") == 0 && t.compare("}") == 0)
            || (s.compare("[") == 0 && t.compare("]") == 0)) {
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        if (s.length() == 1) {
            return false;
        }
        
        stack<string>sta;
        int index = 0;
        while (index < s.length()) {
            string ch = s.substr(index++, 1);
            if (isPushCharacter(ch)) {
                sta.push(ch);
            } else if (isPopCharacter(ch)) {
                if (sta.empty()) {
                    return false;
                }
                if (isTwoCharacterMatch(sta.top(), ch)) {
                    sta.pop();
                } else {
                    // 不匹配return false
                    return false;
                }
            }
        }
        return sta.empty();
    }
};

}


#endif /* ValidParentheses_hpp */
