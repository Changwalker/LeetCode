/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(auto c : s){
            res *= 26;
            res += (c - 'A') + 1;
        }
        return res;
    }
};
// @lc code=end

