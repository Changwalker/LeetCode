/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stk;
        int flag = 1;
        for(int i = 0 ; i < n ; i++)
        {
            if( s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else if(s[i] == ')' ){
                if(stk.empty()) 
                {
                    flag = 0;
                    break;
                }
                else if(stk.top() == '(') 
                    stk.pop();
                else {
                    flag = 0;
                    break;
                }
            }
            else if(s[i] == ']')
            {
                if(stk.empty()) 
                {
                    flag = 0;
                    break;
                }
                else if(stk.top() == '[') 
                    stk.pop();
                else {
                    flag = 0;
                    break;
                }
            }
            else if(s[i] == '}')
            {
                if(stk.empty()) 
                {
                    flag = 0;
                    break;
                }
                else if(stk.top() == '{') 
                    stk.pop();
                else {
                    flag = 0;
                    break;
                }
            }
        }
        if(!stk.empty()) return false;
        else return flag == 1;
    }
};
// @lc code=end

