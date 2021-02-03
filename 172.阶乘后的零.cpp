/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        // 看因子里的5的个数
        // 含有 2 的因子每两个出现一次，含有 5 的因子每 5 个出现一次，2 出现的个数远远多于 5，
        // 找到一个 5，一定能找到一个 2 与之配对。所以我们只需要找有多少个 5。
        // 在这些可被 5 整除的数中, 每间隔 5 个数又有一个可以被 25 整除, 故要再除一次...
        // 直到结果为 0, 表示没有能继续被 5 整除的数了.
        // 5~9——1个 10~14——2个 15~19——3个 20~24——4个 25——5+1=6个

        //小于5时 位数无0
        int count = 0;
        while(n >= 5){
            count += n/5;
            n /= 5;
        }
        return count;
    }
};
// @lc code=end

