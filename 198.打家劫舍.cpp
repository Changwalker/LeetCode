/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // dp——>递推公式： Si为前i间房屋可获钱数，Hi为第i间房可获钱数
        // Sn = max(Sn-1 , Sn-2+Hn)
        // 即偷前n-1间房屋最高金额 或者 偷窃前n-2间房屋的最高金额+加第n间房屋金额
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        // 1.状态数组 前两位初始化 第二家注意取max(H0,H1)
        // vector<int> states(n, 0);
        // states[0] = nums[0];
        // states[1] = max(nums[0], nums[1]);
        // for(int i = 2; i < n; i++){
        //     states[i] = max(states[i-1],states[i-2] + nums[i]);
        // }
        // return states[n-1];

        
        // 2.滚动数组
        int first = nums[0];              // 表S0——>Si-2(第一个至第i-2个的和)
        int second = max(nums[0],nums[1]);// 表S1——>Si-1(第一个至第i-1个的和)
        for(int i = 2; i < n; i++){
            int t = second;     // 暂存second
            second = max(second, first + nums[i]);
            first = t;          // first更新为之前的second 即Si-1
        }
        return second;
    }
};
// @lc code=end

