/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int left = 0, n = nums.size();
        vector<string> res;
        while(left < n){
            string s = "";
            s += to_string(nums[left]);
            int right = left + 1;
            while(right < n && nums[right] == nums[right - 1] + 1)
                right++;
            if(right != left + 1){
                s += "->";
                s += to_string(nums[right - 1]); // 右指针向后多移了一位 -1
            }
            left = right; //下一个left指向当前right 即已向后移动一位的位置
            res.push_back(s);
        }
        return res;
    }
};
// @lc code=end

