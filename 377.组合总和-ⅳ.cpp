/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[x] 表示选取的元素之和等于 x 的方案数，目标是求dp[target]
        // 边界是dp[0]=1。只有当不选取任何元素时，元素之和才为 0，因此只有 1 种方案
        // 遍历i从1到target，对于每个i，进行如下操作：
        // 遍历数组nums中的每个元素num，当num≤i时，将 dp[i−num] 的值加到 dp[i]。
        vector<int> dp(target+1);
        dp[0] = 1;
        for(int i = 1; i <= target; ++i){
            for(int& num : nums){
                if(num <= i && dp[i - num] < INT_MAX - dp[i]){
                    dp[i] +=dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end

