/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // 在散列表中搜索当前元素，如果找到了就返回 true。
        // 在散列表中插入当前元素。
        // 如果当前散列表的大小超过了 k， 删除散列表中最旧的元素。
        set<int> s;
        for(int i = 0; i < nums.size(); ++i){
            if(s.count(nums[i])) return true;
            s.insert(nums[i]);
            if(s.size() > k)
                s.erase(nums[i - k]);
        }
        return false;
    }
};
// @lc code=end

