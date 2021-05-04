/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums){
        int size = nums.size();
        int first = nums[0], second = max(nums[0], nums[1]);
        for(int i = 2; i < size; ++i){
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxval = 0;
        for(int val : nums){
            maxval = max(val,maxval);
        }
        vector<int> sum(maxval + 1);
        for(int val : nums){
            sum[val] += val;// 计算出 x·cx (x为数组中元素，cx为x出现次数)
        }
        return rob(sum);
    }
};
// @lc code=end

