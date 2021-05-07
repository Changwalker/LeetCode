/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        vector<int> nums(n);
        for(int i = 0; i < n; ++i){
            nums[i] = start + 2 * i;
            res ^= nums[i];
        }
        return res;
    }   
};
// @lc code=end

