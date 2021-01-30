/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for(char ch : s){
            if(isalnum(ch)){      //isalnum(c) 如果 c 是一个数字或一个字母，则该函数返回非零值，否则返回 0。
                ss += tolower(ch);//把原字符串转化为全为小写
            }
        }
        string ss_rev = ss;
        reverse(ss.begin(), ss.end());
        return ss == ss_rev;
    }
};
// @lc code=end

