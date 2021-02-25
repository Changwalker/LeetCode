/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        for(int x : nums)
            s.insert(x);
        int i;
        for(i = 0; i <= n; i++){
            if(!s.count(i))
                break;
        }
        return i;
    }
};
// @lc code=end

