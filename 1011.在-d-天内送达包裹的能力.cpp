/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        // 左边界为数组weights中元素的最大值。
        int left = INT_MIN;
        for(auto w : weights)
            if(w > left) left = w;
        // 船的运载能力也不会大于所有包裹的重量之和，
        // 即右边界为数组weights中元素的和。
        int right = accumulate(weights.begin(),weights.end(),0);
        while(left < right){
            int mid = (left + right) / 2;
            int need = 1, cur = 0;// need 为需要的天数，cur 为本天已经运送包裹重量之和
            for(auto w : weights){
                if(cur + w <= mid)
                    cur += w;
                else{
                    need++;
                    cur = w; // 新一天要载上货
                }
            }
            if(need <= D){
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

