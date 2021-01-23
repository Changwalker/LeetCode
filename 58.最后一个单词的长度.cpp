/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int n = s.size();
        if(n == 0) return 0;
        for(int i = n - 1; i >= 0; --i){
            if(s[i] != ' ') 
                res++;
            else if(s[i] == ' ' && res != 0)//"a b "时为1 
                break;
        }
        return res;
    }
};
// @lc code=end

