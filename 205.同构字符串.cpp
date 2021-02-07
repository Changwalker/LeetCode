/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            char x = s[i], y = t[i];
            if((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x))
                return false;
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};
// @lc code=end

