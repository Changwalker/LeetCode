/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //三个数最大乘积 三个数中含负数时，必为两负一正 即最小两个和最大一个
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int res1 = 1, res2 = 1;
        for(int i = n-1 ; i >= n-3 ; i-- )
            res1 *= nums[i];
        res2 = nums[0] * nums[1] * nums[n-1];
        return max(res1, res2);
    }
};
// @lc code=end

