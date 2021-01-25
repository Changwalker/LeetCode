/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void dfs(int cur, int n, int k){
        // 剪枝：若temp长度加区间[cur, n]的长度小于 k，不可能构造出长度为 k 的 temp
        if(temp.size() + (n - cur + 1) < k){
            return;
        }
        //记录合法答案
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        //考虑选择当前位置
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        //考虑不选择当前位置
        temp.pop_back();
        dfs(cur + 1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};
// @lc code=end

