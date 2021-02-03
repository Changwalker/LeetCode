/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int low = 0, high = numbers.size() - 1;
        while(low < high){
            int sum = numbers[low] + numbers[high];
            if(sum == target){
                res.push_back(low + 1);
                res.push_back(high + 1);
                return res;
            }
            else if(sum < target)
                low ++;
            else if(sum > target)
                high --;
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};
// @lc code=end

