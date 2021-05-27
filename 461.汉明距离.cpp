/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        // 使用异或运算， 输入位（x y）某位不同时输出1
        // 1.语言内置：位计数功能
        // return __builtin_popcount(x ^ y);

        // 2.移位实现位计数 s=x^y 不断右移看最低位是否为1 直到s为0
        // int s = x ^ y, res = 0;
        // while(s){
        //     res +=s & 1;
        //     s >>= 1;
        // }
        // return res;
        
        // 3.Brian Kernighan 算法
        // 记 f(x) 表示 x 和 x-1 进行与运算所得的结果（即f(x)=x & (x−1)），
        // 那么 f(x) 恰为 x 删去其二进制表示中最右侧的 1 的结果。
        // 基于该算法，当我们计算出s=x⊕y，只需要不断让s=f(s)，直到s=0 即可。这样每循环一次，s 都会删去其二进制表示中最右侧的1，最终循环的次数即为 s 的二进制表示中 1 的数量。
        int s = x ^ y, res = 0;
        while(s){
            s &= (s - 1);
            res ++;
        }
        return res;
    }
};
// @lc code=end

