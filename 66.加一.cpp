/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res;
        if(digits[n-1] + 1 < 10){
            digits[n-1] += 1;
            for(int i = 0; i < n; ++i)
                res.push_back(digits[i]);
            return res;
        }
        else{
            int carry = 0;
            int sum = 0;
            for(int i = n - 1; i >= 0 ;--i){
                if(i == n-1) digits[i] += 1;
                sum = carry + digits[i];
                carry = sum / 10;
                sum %= 10;
                res.push_back(sum);
            }
            if(carry != 0) 
                res.push_back(carry);
            reverse(res.begin(),res.end());
            return res;
        }
    }
};
// @lc code=end

