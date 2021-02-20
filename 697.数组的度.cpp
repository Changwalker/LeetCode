/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // https://leetcode-cn.com/problems/degree-of-an-array/solution/xiang-xi-fen-xi-ti-yi-yu-si-lu-jian-ji-d-nvdy/
        unordered_map<int,int> left, right, counter;// left记录数组中元素首次出现位置，right记录最后出现位置
        int degree = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(!left.count(nums[i]))// 如果left中没出现过当前值 将left哈希表中当前值的key设置为i
                left[nums[i]] = i;
            right[nums[i]] = i;     // right哈希表中始终更新该值当前位置i
            counter[nums[i]]++;     // 计数器更新该值的出现次数以计算数组的度
            degree = max(degree, counter[nums[i]]);
        }
        int res = nums.size();
        //加&是引用，如果没有&，每次遍历都会给重新开辟空间存放遍历的值，空间复杂度是O（n），而使用引用的话，即使用同一块空间。
        // 同时，引用的情况下可以修改原来的值。
        for(auto& x : counter){
            if(x.second == degree){
                res = min(res, right[x.first] - left[x.first] + 1);// 找出元素 k 最后一次出现的位置 和 第一次出现的位置，计算两者之差+1，即为子数组长度。
            }
        }
        return res;
    }
};
// @lc code=end

