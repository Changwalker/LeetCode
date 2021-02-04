/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // 滑动窗口
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < k; ++i){// 看第一个窗口
            sum += nums[i];
        }
        int res = sum;             // 暂存第一个窗口sum为最大
        for(int i = k; i < n; ++i){// 窗口向后移 每次一位 便要加新窗口新加的 减去旧窗口的（滑动）
            sum = sum + nums[i] - nums[i - k];
            res = max(res, sum);
        } 
        return (double)res/k;
    }
};
// @lc code=end

