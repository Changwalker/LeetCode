/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> count(26, 0);
        for(auto &ch : s){
            count[ch - 'a']++;
        }
        for(auto ch : t){
            count[ch - 'a']--;
            if(count[ch - 'a'] < 0) //若含不在s中的字符，则会出现负数，或者 若含s中字符但数量不一致 也会出现负数
                return false;
        }
        return true;
    }
};
// @lc code=end

