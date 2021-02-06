/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getsum(int &x){
        int sum = 0;
        while(x > 0){
            sum += (x%10)*(x%10);
            x /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        // https://leetcode-cn.com/problems/happy-number/solution/kuai-le-shu-by-leetcode-solution/
        // 第 1 部分我们按照题目的要求做数位分离，求平方和。
        // 第 2 部分可以使用哈希集合完成。
        // 每次生成链中的下一个数字时，我们都会检查它是否已经在哈希集合中。     
        

        set<int> seen;
        while(n != 1 && !seen.count(n)){// 如果它不在哈希集合中，我们应该添加它。
            seen.insert(n);             // 如果它在哈希集合中，这意味着我们处于一个循环中，因此应该返回 false。
            n = getsum(n);
        }
        return n == 1;
    }
};
// @lc code=end

