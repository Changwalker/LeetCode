/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i - 1] > nums[i]){
                if(i == 1 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];

                else{
                    nums[i] = nums[i - 1];
                }
                count ++;
            }
        }
        return count <= 1;
    }
};
// @lc code=end

