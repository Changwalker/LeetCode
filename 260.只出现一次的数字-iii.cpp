/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 题解：https://leetcode-cn.com/problems/single-number-iii/solution/zhi-chu-xian-yi-ci-de-shu-zi-iii-by-leet-4i8e/
    // 异或 相同为0 不同为1
    // 先对所有数字进行一次异或，得到两个出现一次的数字的异或值。
    // 在异或结果中找到任意为 1 的位。根据这一位对所有的数字进行分组。
    // 在每个组内进行异或操作，得到两个数字。
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto x:nums)
            res ^=x;
        int div = 1; 
        while((div & res) == 0)// 找到异或和中等于1的一位（可任取，本题中取不为 0 的最低位）
            div <<= 1;
        int a = 0, b = 0;
        // 分组，使得：
        // 两个只出现一次的数字在不同的组中；
        // 相同的数字会被分到相同的组中。两组组内异或，即可得到只出现一次的数字
        for(auto n:nums){
            if(div & n){
                a ^= n;
            }
            else {
                b ^= n;
            }
        }
        return vector<int>{a,b};
    }
};
// @lc code=end

