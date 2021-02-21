/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        // 1.左右乘积数组
        // vector<int> left(n, 0),right(n, 0);
        // left[0] = 1;
        // right[n - 1] = 1;
        // for(int i = 1; i < n; i++){
        //     left[i] = nums[i - 1] * left[i - 1];
        // }
        // for(int i = n - 2; i >= 0; i--){
        //     right[i] = nums[i + 1] * right[i + 1];
        // }
        // for(int i = 0; i < n; i++){
        //     res[i] = left[i] * right[i];
        // }
        // return res;
        // 1 1 2 6
        // 2.O(1)空间方法 res作为left从左到右更新 定义right为变量从右到左边更新自身边更新res
        int right = 1;
        res[0] = 1;
        for(int i = 1; i < n; i++){
            res[i] = nums[i - 1] * res[i - 1];
        }
        for(int i = n - 1; i >= 0; i--){
            res[i] = res[i] * right;
            right = right * nums[i];
        }
        return res;
    }
};
// @lc code=end

