/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string res = strs[0];
        for(int i = 1 ;i < strs.size() ; i++)
        {
            int j = 0;
            while(j < res.size() && j < strs[i].size())
            {
                if(res[j] != strs[i][j])
                    break;
                j++;
            }
            res = res.substr(0,j);
            if(res == "")
                return res;
        }
        return res;
    }
};
// @lc code=end

