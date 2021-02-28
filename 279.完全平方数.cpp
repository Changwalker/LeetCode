/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // https://leetcode-cn.com/problems/perfect-squares/solution/hua-jie-suan-fa-279-wan-quan-ping-fang-shu-by-guan/
    // dp[i]：表示完全平方数和为i的 最小个数
    // 初始状态dp[i]均取最大值i，即 1+1+...+1，i个1; dp[0] = 0
    // dp[i] = min(dp[i], dp[i-j*j]+1)，其中, j是平方数, j=1~k,其中k*k要保证 <= i
    // 意思就是：完全平方数和为i的 最小个数 等于 当前完全平方数和为i的 最大个数
    // 与 （完全平方数和为 i - j * j 的 最小个数 + 完全平方数和为 j * j的 最小个数）
    // 可以看到 dp[j*j] 是等于1的
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; i++){
            dp[i] = i;
            for(int j = 1; i - j * j >=0; j++){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

