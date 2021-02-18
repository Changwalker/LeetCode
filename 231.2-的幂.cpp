/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 方法：去除二进制中最右边的 1：
        // 首先讨论为什么 x & (x - 1) 可以将 最右边的1 设置为0。
        // (x - 1) 代表了将 x 最右边的 1 设置为 0，并且将较低位设置为 1。
        // 再使用与运算：则 x 最右边的 1 和就会被设置为 0，因为 1 & 0 = 0。
        
        // 因为若一个数x为 2 的幂 则x的二进制中只含有一个 1。
        // x-1的这一位为0后面全为1（例：8：1000 7：0111）
        // x & (x - 1) 结果就为0，因此判断是否为 2 的幂 即 判断 x & (x - 1) == 0。
        if(n <= 0)  return false;
        return (n & (n-1)) == 0;
    }
};
// @lc code=end

