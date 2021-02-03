/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int maxn = INT_MIN;
        int res = 0;
        for(auto x : nums){
            count[x]++;
            if(count[x] > maxn){
                maxn = count[x];
                res = x;
            }
        }
        return res;
    }
};
// @lc code=end

