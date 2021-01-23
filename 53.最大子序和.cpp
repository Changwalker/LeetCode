/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        for(int i = 0; i < nums.size(); ++i ){
            sum += nums[i];
            res = max(sum, res);
            if(sum < 0) 
                sum = 0;
        }
        return res;
    }
};
// @lc code=end

