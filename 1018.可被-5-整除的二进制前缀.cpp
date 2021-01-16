/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        int sum = 0;
        for(int i = 0;i < A.size() ;i++)
        {
            sum = (sum * 2 + A[i]) % 5;
            ans.push_back(sum == 0);
        }
        return ans;
    }
};
// @lc code=end

