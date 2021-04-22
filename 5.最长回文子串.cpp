/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
        // 状态转移方程：P(i,j)=P(i+1,j−1)∧(S[i] = s[j])
        // 也就是说，只有 s[i+1:j-1] 是回文串，并且s的第i和j个字母相同时，s[i:j] 才会是回文串。
        int n = s.size();
        int maxlen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        for(int l = 2; l <= n; l++){ // 左边界枚举
            for(int i = 0; i < n; i++){
                int j = l + i - 1;//l和i确定右边界j
                if(j >= n) break;
                if(s[i] != s[j])
                    dp[i][j] = false;
                else //s[i] == s[j]时
                {
                    if(j - i < 3){//aaa aa a
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if(dp[i][j] == true && j - i + 1 > maxlen){
                    maxlen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin,maxlen);
    }
};
// @lc code=end

