/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // return (int)sqrt(x);
        if(x <= 1) return x;
        int l = 0, r = x, res =INT_MIN;
        while(l <= r){
            long long mid = (l + r) / 2;
            long long temp = mid * mid;
            if(temp <= x){ //当前mid比目标值小 界重定为右半部分
                res = mid;
                l = mid + 1;
            } 
            else {         //当前mid比目标值小 界重定为右半部分  
                r = mid -1;
            }
        }
        return res;
    }
};
// @lc code=end

