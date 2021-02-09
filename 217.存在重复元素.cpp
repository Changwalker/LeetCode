/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto a : nums)
            s.insert(a);
        int n1 = nums.size();
        int n2 = s.size();
        return n1 != n2;
    }
};
// @lc code=end

