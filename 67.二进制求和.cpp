/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int na = a.size();
        int nb = b.size();
        while(na > nb){
            b = '0' + b;
            nb++;
        }
        while(na < nb){
            a = '0' + a;
            na++;
        }
        int carry = 0;
        for(int i = na - 1; i >= 0; --i){//a作为返回数组
            int sum = a[i] - '0' + b[i] - '0' + carry;
            a[i] = sum % 2 + '0';
            carry = sum / 2;
        }
        if(carry > 0)
            a = '1' + a;
        return a;
    }
};
// @lc code=end

