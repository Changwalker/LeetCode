/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //从前K个逆向滑到后K个 以尾部为基准 从n-k位到n-1位
        int n = cardPoints.size();
        int left = 0, right = 0;
        int sum =0;
        for(int i = 0; i < k; ++i){
            sum += cardPoints[i];
        }
        int res = sum;
        for(int i = 0; i < k; ++i){
            sum += cardPoints[n - 1 - i];// 从第一位往前滑动 前k个滑到i后k个
            sum -= cardPoints[k - 1 - i];
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end

