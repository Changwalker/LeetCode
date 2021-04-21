/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long x = dividend, y = divisor;
        bool nega = false;
        if((x > 0 && y < 0) || (x < 0 && y > 0)) 
            nega = true;
        if(x < 0) x = -x;
        if(y < 0) y = -y;
        //二分结果
        long long  left = 0, right = x;// 二分结果在0~x之间
        while(left < right){
            long mid = (left + right + 1) >> 1;
            if(mul(mid, y) <= x){// 商×除数 <= 被除数
                left = mid;
            }
            else{                // 商×除数 >  被除数
                right = mid - 1;
            }
        }

        long long ans = nega ? -left : left;
        if(ans > INT_MAX || ans < INT_MIN)
            return INT_MAX;
        return (int)ans;
    }
    //快速乘法
    long long mul(long long a, long long b){
        long long ans = 0;
        while(b > 0){
            if((b & 1) == 1) ans += a;
            b >>= 1;
            a += a;
        }
        return ans;
    }
};
// @lc code=end

