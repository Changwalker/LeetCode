/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> num1(nums1.begin(),nums1.end());
        for(int num : nums2){
            if(num1.count(num))
                result.insert(num);
        }
        return vector<int>(result.begin(),result.end();
    }
};
// @lc code=end

