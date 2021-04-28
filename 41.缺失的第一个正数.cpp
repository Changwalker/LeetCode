/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 交换数组中位置a和位置b对应的元素
    void swap(vector<int> &nums,int a, int b){ 
        int t = nums[a];
        nums[a] = nums[b];
        nums[b] = t;
    }
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            // nums[0] = 1,nums[1] = 2... nums[n] = n + 1
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]){
                swap(nums, i, nums[i] - 1);
            }
        }
        for(int i = 0; i < n; ++i){
            if(nums[i] != i + 1) return i + 1;
        }
        // 前面每个位置都符合 返回最后数组元素个数+1
        // e.g. [1,2,3,4,5] n = 5,要返回n + 1 = 6
        return n + 1;  
    }
};
// @lc code=end

