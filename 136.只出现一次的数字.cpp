/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {//位运算：异或（相同为0）
    // 任何数和 00 做异或运算，结果仍然是原来的数，即 a⊕0=a。
    // 任何数和其自身做异或运算，结果是 0，即 a⊕a=0。
    // 异或运算满足交换律和结合律，即 a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b。
    // 重点：一个元素 1 次 其余元素均 2 次  
    // 所以所有数相异或 结果应该等于出现一次的那个数
    int res = 0;
    for(auto a : nums)
        res ^= a;
    return res;
    }
};
// @lc code=end

