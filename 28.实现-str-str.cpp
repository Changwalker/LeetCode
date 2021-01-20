/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //KMP
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {  
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
    //暴力
        // int i, n1 = haystack.size(), n2 = needle.size();
        // if(n2 == 0) 
        //     return 0;
        // for(i = 0; i < n1; ++i){
        //     for(int j = 0; j < n2; ++j){
        //         if(haystack[i + j] != needle[j])
        //             break;
                
        //         if(j == n2 - 1) return i;
        //     }
        // }
        // return -1;  
};
// @lc code=end

