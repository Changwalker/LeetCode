/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        // 哈希表 sumA−x+y=sumB+x−y -->x = y+(suma-sumb)/2
        // 即对于数组 B 中的任意一个数 y' 
        // 只要A中存在一个数x' 满足x'=y'+(suma-sumb)/2
        // {x', y'} 即一组可行解
        // 这道题其实就是给你两个数组，让你从两个数组中分别选取一个进行交换，
        // 使得交换后的数组和相等。

        // 因此我们可以提前计算出两个数组的差，并将其中一个数组放到哈希表中。
        // 这样问题就转换为:
        // 遍历另外一个数组，并在哈希表中查找 x + delta 是否在哈希表中存在即可，
        // 其中 x 为当前遍历到的数，delta 为两个数组的差。 
        // 这就是经典的两数和问题了。

        vector<int> ans;
        int sumA = 0, sumB = 0;
        for(auto &x : A)
            sumA += x;
        for(auto &x : B)
            sumB += x;
        int delta = (sumA - sumB) / 2;
        unordered_set<int> rec(A.begin(), A.end());
        for (auto& y : B) {
            int x = y + delta;
            if (rec.count(x)) { // 哈希表中找到该数
                ans.push_back(x);
                ans.push_back(y);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

