/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for(int n : nums){
            if(n != 0)
                nums[index ++] = n;
        }
        for(int i = index; i < nums.size(); ++i)
            nums[i] = 0;
        // 双指针
        // int n = nums.size();
        // int left = 0, right = 0;
        // while(right < n){
        //     if(nums[right]){
        //         swap(nums[left], nums[right]);
        //         left ++;
        //     }
        //     right ++;
        // }
    }
};
// @lc code=end

