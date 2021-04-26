/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MIN;
        for(auto x : piles)
            if(x > right)
                right = x;
        while(left < right){
            int need = 0;
            int mid = left + (right - left) / 2;
            for(auto n : piles){
                need += (n - 1) / mid + 1;//向上取整
                // 等价于need += n / mid + (n % mid == 0? 0:1);
            }
            if(need <= h)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end

