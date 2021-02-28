/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = true, dec = true;
        int n = A.size();
        for(int i = 0; i < n - 1; ++i){
            if(A[i + 1] > A[i])
                inc = false;
            if(A[i + 1] < A[i])
                dec = false;
        }
        return (inc || dec);
    }
};
// @lc code=end

