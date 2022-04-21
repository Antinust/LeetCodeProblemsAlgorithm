//
//  LetterCombinations.h
//  Demo
//
//  Created by zcc_imac on 2022/4/7.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LetterCombinations_h
#define LetterCombinations_h

#import "PublicCommon.h"
namespace LetterCombinations {

class Solution {
public:
    void dfs(vector<string> &letters, int numSize, vector<vector<bool>> &used, vector<string> &ans, string &tempStr, int depth) {
        if (depth >= numSize) {
            ans.push_back(tempStr);
            return; // 要 注意 及时return
        }
        
        for (int i = 0; i < used[depth].size(); i++) {
            if (!used[depth][i]) {
                used[depth][i] = true;
                tempStr.append(string(1, letters[depth][i]));
                dfs(letters, numSize, used, ans, tempStr, depth + 1);
                tempStr.pop_back();
                used[depth][i] = false;
            }
        }
        
    }
    
    vector<string> letterCombinations(string s) {
        int sLen = s.length();
        vector<string> ans;
        
        if (sLen < 1) {
            return ans;
        }
        vector<string> originLetters{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> letters;
        for (int i = 0; i < sLen; i++) {
            letters.push_back(originLetters[s[i] - '2']);
        }
        
        vector<vector<bool>> used;
        for (int i = 0; i < letters.size(); i++) {
            used.push_back(vector<bool>(letters[i].size() ,0));
        }

        string tmpStr;
        dfs(letters, s.size(), used, ans, tmpStr, 0);
        return ans;
    }
};

}

#endif /* LetterCombinations_h */
