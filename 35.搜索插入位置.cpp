/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = n - 1 ;i >= 0 ; --i){
            if(target > nums[i]){
                return i + 1;
            }
        }
        return 0;
    }
};
// @lc code=end

