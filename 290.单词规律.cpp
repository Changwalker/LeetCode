/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> strToch;
        unordered_map<char, string> chTostr;
        int n = s.size();
        int i = 0;
        for(auto ch : pattern){
            if(i >= n)
                return false;
            int j = i;
            // 切割s中的单词
            while(j < n && s[j] != ' ') 
                j++;
            const string &tmp = s.substr(i, j - i);

            // 判断单词和字符对应
            if(strToch.count(tmp) && strToch[tmp] != ch){
                return false;
            }
            if(chTostr.count(ch) && chTostr[ch] != tmp){
                return false;
            }
            strToch[tmp] = ch;
            chTostr[ch] = tmp;
            i = j + 1;
        }
        return i >= n;
    }
};
// @lc code=end

