/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        int temp = 0;
        while(n > 0){
            // 重点：要减一！
            // 转换成从0开始而不是从1开始，0-25对应者'A'-'Z'，就是标准的26进制了，
            // 第二轮循环可以看成对一个新的n 。
            n--;
            temp = n % 26;
            res.push_back('A' + temp);
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

