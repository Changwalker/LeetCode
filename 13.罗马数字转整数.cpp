/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {//从头开始遍历，若当前字母大于后一个则加 若当前字母小于后一个则减
        int n = s.size();
        int res = 0;
        
        map<char,int> roman={//初始化哈希表
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D', 500},
            {'M', 1000}
        };
        for(int i = 0; i < n ; ++i){
            if(roman[s[i]] < roman[s[i+1]])
                res -= roman[s[i]];
            else
            {
                res += roman[s[i]];
            }
        }
        return res;
    }
};
// @lc code=end

