/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 枚举mask从0到2^n-1 mask二进制值表示0/1序列，
    // (000 001 010 011 100 101 110 111)
    // 按照这个0/1序列在原集合取数。
    // 当我们枚举完所有2^n个mask就能构造出所有子集
    vector<int> t;
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for(int mask = 0; mask <(1 << n) ; ++mask){
            t.clear();                      //位运算
            for(int i = 0; i < n; ++i){     // e.g1 101 & 001 != 0 101 & 100 != 0
                if(mask & (1 << i)){        // e.g2 101 & 010 == 0
                    t.push_back(nums[i]);   // 即只要不是每位相反结果就不为0
                }
            }
            //一趟后产生的集合 存入ans
            ans.push_back(t);
        }
        return ans;
    // 递归法枚举（类似77.组合）
    // void dfs(int cur, vector<int>& nums) {
    //     if (cur == nums.size()) {
    //         ans.push_back(t);
    //         return;
    //     }
    //     t.push_back(nums[cur]);
    //     dfs(cur + 1, nums);
    //     t.pop_back();
    //     dfs(cur + 1, nums);
    // }

    // vector<vector<int>> subsets(vector<int>& nums) {
    //     dfs(0, nums);
    //     return ans;
    // }
    }   
};
// @lc code=end

