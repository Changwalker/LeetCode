/*
 * @lc app=leetcode.cn id=1482 lang=cpp
 *
 * [1482] 制作 m 束花所需的最少天数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // 题解（写的很好）：https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/solution/xiao-ming-chong-hua-by-xiaohu9527-5jf6/
        // 二分查找：将左边界定义为了数组中的最小值。
        // 右边界定义为了数组的最大值。
        // 每一次都计算其中间值，然后判断在这个天数里会有哪些花开，以及这么多花可以制作多少花束。
        // 如果可制作花束少于要求 m 朵, 则他将 left 调整指 mid + 1 的天数位置，使其中间值变大可以开更多的花从而能做更多的花束达到 m 朵的要求。
        // 如果可制作花束过多或者刚好等于 m 朵，则他将 right 调整指 mid 的天数位置, 使其中间值变小求需要的最小的天数。
        // 再计算能在 m 天内能制作多少朵花束的同时，他也没有忘记制作的花束只能用相邻的两朵花！！！因此对于有存在连续的 k 朵花盛开，他会将可以制作的花 +1, 然后将花朵的计数重新设为 0 继续计算。
        int n = bloomDay.size();
        if(m * k > n) return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        while(l < r){
            int mid = (l + r) >> 1;
            int numMake = 0, numBloom = 0;
            for(int x : bloomDay){
                // numBloom = x <= mid ? numBloom + 1 : 0;
                if(x <= mid){
                    numBloom = numBloom + 1;
                }
                else{
                    numBloom = 0;
                }
                if(numBloom == k){// 判断连续k
                    numMake++;
                    numBloom = 0;
                }
            }
            if(numMake < m) l = mid + 1;
            else r = mid;
        }
        return l;
    }   
};
// @lc code=end

