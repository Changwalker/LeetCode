/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string str;
        for(auto& ch : s){
            if(ch == '('){
                stk.push(str);
                str = "";
            }
            else if(ch == ')'){
                reverse(str.begin(),str.end());
                str = stk.top() + str;
                stk.pop();
            }
            else
                str += ch;
        }
        return str;
    }
};
// @lc code=end

