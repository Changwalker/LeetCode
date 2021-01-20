/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = 0;
        for(int i = 0;i < nums.size() ; ++i){
            if(nums[i] != val)
                nums[n++] = nums[i];
        }
        return n;
    }
};
// @lc code=end

