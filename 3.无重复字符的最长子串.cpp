/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        unordered_set<char> see;
        int left = 0, res = 0;
        for(int right = 0; right < s.size(); ++right){
            // 这段代码结果是不断从左缩小窗口，直到窗口中不存在与下一个字符重复的字符。
            // see.find() 查找对应元素，成功返回对应的迭代器，
            // 失败返回最后一个元素迭代器（即 see.end() ）

            // see.end() 不是最后添加进去的元素对应的迭代器，
            // 是最后添加进去的元素对应的迭代器的下一个（最后一个元素对应的迭代器）。
            while(see.find(s[right]) != see.end()){ // 在集合中查找到，即有重复
                see.erase(s[left]);
                left++;
            }
            res = max(res, right - left + 1);
            see.insert(s[right]);
        }
        return res;
    }
};
// @lc code=end

