/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {//递归+循环
        if(n == 1) return "1";                        //n = 1时：固定为1

        string previous = countAndSay(n - 1);         //后一个读出前一个数
        string res = "";

        int count = 1;
        for(int i = 0; i < previous.length(); ++i){
            if(previous[i] == previous[i+1])          //遇到重复数字:111 count = 3
                count++;
            else{                                     //没有重复数字
                res += to_string(count) + previous[i];//3个1->"31"
                count = 1;//复原计数器
            }
        }
        return res;
        // 1      ->1
        // 1      ->11
        // 11     ->21
        // 21     ->12 11
        // 111221 ->31 22 11
    }
};
// @lc code=end

