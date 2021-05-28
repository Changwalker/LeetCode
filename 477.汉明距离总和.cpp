/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        // 由于数组中元素范围从0到 10^9 <2^30 所以从二进制的第0位枚举到第29位
        for(int i = 0; i < 30; ++i){ //对于nums中每个元素 从最低位到最高位
            int c = 0;
            for(int val : nums){
                c += (val >> i) & 1; //统计出所有元素的第i位共有c个1， n-c个0
            }
            ans += c * (n - c);
        }
        return ans;
    }
};
// @lc code=end

