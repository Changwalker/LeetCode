/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // nums = [3,30,34,5,9]
        // 自定义一种排序方式 比较 s1 + s2 和 s2 + s1
        sort(nums.begin(), nums.end(), [](const int &x,const int &y){
           long sx = 10, sy = 10;
           while(sx <= x){
               sx *= 10;
           }
           while(sy <= y){
               sy *= 10;
           }
           return sy * x + y > sx * y + x; //比较前后两数拼接后大小关系 返回较大的顺序
        });
        if(nums[0] == 0)
            return "0";
        string res;
        for(int &x : nums){
            res += to_string(x);
        }
        return res;
    }
};
// @lc code=end

