/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //https://leetcode-cn.com/problems/ugly-number-ii/solution/chou-shu-ii-by-leetcode/
    int nthUglyNumber(int n) {
        vector<int> res(1690,0);
        int p2 = 0, p3 = 0, p5 = 0;
        res[0] = 1;
        for(int i = 1;i < 1690; ++i){
            int minnum = min(min(res[p2]*2, res[p3]*3),res[p5]*5);
            res[i] = minnum;
            if(res[p2] * 2 == minnum) p2++;
            if(res[p3] * 3 == minnum) p3++;
            if(res[p5] * 5 == minnum) p5++;
        }
        return res[n - 1];
    }
};
// @lc code=end

