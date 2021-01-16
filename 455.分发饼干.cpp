/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j = 0;
        for(int i = 0; i < s.size(); ++i ) //以饼干大小为基准，遍历孩子
        {
            if(j < g.size() && g[j] <= s[i])
            {
                ans++;
                j++;
            }
        }
        return ans;
    }
};
// @lc code=end

