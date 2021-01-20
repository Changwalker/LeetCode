/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //数组完成排序后，我们可以放置两个指针 i 和 j，
        //其中 i 是慢指针,而 j 是快指针。
        //只要nums[i]==nums[j] 便j++跳过重复项
        //当nums[i]!=nums[j]时，要把nums[j]的值复制到nums[i+1]然后递增i
        if(nums.size() == 0) return 0;
        int n = 0;
        for(int i = 1 ;i < nums.size() ; ++i){
            if(nums[i] != nums[n]){
                n++;
                nums[n] = nums[i];
            }
        }
        return n+1;
    }
};
// @lc code=end

