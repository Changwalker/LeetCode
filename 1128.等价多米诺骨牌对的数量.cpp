/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // 本题中我们需要统计所有等价的多米诺骨牌，其中多米诺骨牌使用二元对代表，
        // 「等价」的定义是，在允许翻转两个二元对的的情况下，使它们的元素一一对应相等。 
        // 于是我们不妨直接让每一个二元对都变为指定的格式，即第一维必须不大于第二维。
        // 这样两个二元对「等价」当且仅当两个二元对完全相同。 
        // 注意到二元对中的元素均不大于 99，因此我们可以将每一个二元对拼接成一个两位的正整数，
        // 即 (x, y) -> 10x + y 
        // // 这样就无需使用哈希表统计元素数量，而直接使用长度为 100100 的数组即可。
        vector<int > num(100);
        int res = 0;
        for(auto &it :dominoes){
            int val = it[0]<it[1] ? it[0]*10 + it[1] : it[1]*10 + it[0];
            //(x,y): x<=y时 -> 10x+y x>y时 -> 10y+x
            res += num[val];
            num[val]++;
        }
        return res;
    }
};
// @lc code=end

