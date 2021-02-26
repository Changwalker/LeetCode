/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // 窗口每次主动向右扩张，然后窗口的左侧来使用窗口，
        // 以保证窗口内的数据和是小于等于sum-x的（因为每个数据都大于0）
        // 当窗口内的数据恰好等于sum-x时，则将窗口长度记录比较最小值

        int left = 0, right = 0, maxPart = -1;
        int sum = 0;
        for(int n : nums)
            sum += n;
        int target = sum - x;
        if(target < 0) 
            return -1;
        while(right < nums.size()){
            target -= nums[right++];
            while(target < 0) 
                target += nums[left++];
            if(target == 0) maxPart = max(maxPart, right - left);
        }
        int res = nums.size() - maxPart;
        return maxPart == -1? -1:res;
    }
};
// @lc code=end

