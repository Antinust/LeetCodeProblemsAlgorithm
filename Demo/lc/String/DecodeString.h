//
//  DecodeString.h
//  Demo
//
//  Created by zcc_imac on 2022/4/5.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef DecodeString_h
#define DecodeString_h
#import "PublicCommon.h"

namespace DecodeString {

/*
 注意数字是1-300之间
 
 // char topChar = sta.top() - '0';

 */

class Solution {
public:

    string decodeString(string s) {
        
        stack<char> sta;
        string ans;
        int sLen = s.length();
        int index = 0;
        while (index < sLen) {
            if (s[index] == ']') {
                string strInBracket;
                while (sta.top() != '[') { // !sta.empty() &&
                    strInBracket.insert(0, string(1, sta.top()));
                    sta.pop();  //别忘记pop迭代操作
                }
                sta.pop();
                
                //处理数字
                int num = sta.top() - '0';
                sta.pop();
                int kth = 1;
                while (!sta.empty() && sta.top() >= '0' && sta.top() <= '9') {
                    num += pow(10, kth++) * (sta.top() - '0');
                    sta.pop();
                }
                
                while (--num >= 0) {
                    for (int i = 0; i < strInBracket.size(); i++) {
                        sta.push(strInBracket[i]);
                    }
                }
            } else {
                sta.push(s[index]);
            }
            index++;
        }
        
        while (!sta.empty()) {
            ans.insert(0, string(1, sta.top()));
            sta.pop();
        }
        return ans;
    }
};


// 下面是错误的写法，因审题不清导致，没有考虑嵌套[]的情况

//class Solution {
//public:
//
//    string decodeString(string s) {
//        string ans;
//        int sLen = s.length();
//
//        int leftBracketIndex = 0;
//
//        int index = 0;
//        while (index < sLen) {
//
//            while (index < sLen && s[index] != '[') {
//                if (s[index] >= 'a' && s[index] <= 'z') {
//                    ans.append(string(1, s[index]));
//                }
//                index++;
//            }
//            if (index < sLen) {
//                leftBracketIndex = index;
//                index++;
//                while (index < sLen && s[index] != ']') {
//                    index++;
//                }
//                string strInBracket = s.substr(leftBracketIndex + 1, index - leftBracketIndex - 1);
//                int num = s[leftBracketIndex - 1] - '0';
//                while (--num >= 0) {
//                    ans.append(strInBracket);
//                }
//            }
//            index++;
//        }
//        return ans;
//    }
//};

}

#endif /* DecodeString_h */
