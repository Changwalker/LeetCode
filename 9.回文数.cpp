/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) 
            return false;
        //逆置比较一半即可 比较和原数一半是否相等
        int rev = 0;   
        while(rev < x) 
        {              
            rev = rev * 10 + x % 10;//求（一半）逆置数
            x /= 10;
        }
        return (rev == x || rev/10 == x);
    }
};
// @lc code=end
// 10:1 0;0 1
// 11:1 1(rev==x)
// 123:12 3;1 32 
// 1221:122 1;12 12 (rev==x)
// 12221:1222 1;122 12;12 122 (rev/10 == x)