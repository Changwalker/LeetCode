/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        // dp[i]含义为s[0~i]的译码方法总数 dp[-1] = dp[0] = 1 
        // cur指向i pre指向i-1 (滚动数组)
        int pre = 1, cur = 1; 
        for(int i = 1; i < s.size(); i++){
            int tmp = cur; // 保存dp[i]
            // 若s[i]='0' 那么若s[i-1]='1'or'2',则dp[i] = dp[i-2] 此时s[i-1]+s[i]唯一被译码，不增加情况
            if(s[i] == '0') 
                if(s[i - 1] == '1' || s[i - 1] == '2') cur = pre;
                else return 0;
            // 若s[i-1]='1'/s[i-1]='2'且'1'<=s[i]<='6'时 则dp[i] = dp[i-1]+dp[i-2] 即s[i-1]与s[i]分开译码，为dp[i-1]，合并译码，为dp[i-2]
            else if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
                cur = cur + pre;
            pre = tmp; // 记录下轮的dp[i-1] 等于之前的dp[i]
        }
        return cur;
    }
};
// @lc code=end

