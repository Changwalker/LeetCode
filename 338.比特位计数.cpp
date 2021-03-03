/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // https://leetcode-cn.com/problems/counting-bits/solution/bi-te-wei-ji-shu-by-leetcode-solution-0t1i/
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        for(int i = 1; i <= num; ++i){
            bits[i] = bits[i >> 1] + (i & 1); //(i & 1)为求i除2余数
        }
        return bits;
    }
};
// @lc code=end

