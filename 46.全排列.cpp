/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
    void dfs(vector<vector<int>> &res, vector<int> output, int first, int len){
        if(first == len){
            res.emplace_back(output);
            return;
        }
        for(int i = first; i < len; i++){
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个位置
            dfs(res, output, first + 1, len);
            // 回溯后撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, nums, 0, (int)nums.size()); 
        return res;
    }
};
// @lc code=end

