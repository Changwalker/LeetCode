/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0){
            int pop = x % 10;
            x = x / 10;
            if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > INT_MAX % 10)){//最大
                rev = 0;
                break;
            }
            else if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < INT_MIN % 10)){//最小
                rev = 0;
                break;
            }
            rev = rev * 10 + pop;
        }
        return rev;
        // int rev =0;
        // while(x != 0)
        // {
        //     if(rev > 214748364 || rev < -214748364) return 0;
        //     rev = rev * 10 + x % 10;
        //     x /= 10;
        // }
        // return rev;
    }
};
// @lc code=end

