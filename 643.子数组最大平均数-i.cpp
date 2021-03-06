/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // 滑动窗口 模板
        // def findSubArray(nums):
        //     N = len(nums) # 数组/字符串长度
        //     left, right = 0, 0 # 双指针，表示当前遍历的区间[left, right]，闭区间
        //     sums = 0 # 用于统计 子数组/子区间 是否有效，根据题目可能会改成求和/计数
        //     res = 0 # 保存最大的满足题目要求的 子数组/子串 长度
        //     while right < N: # 当右边的指针没有搜索到 数组/字符串 的结尾
        //         sums += nums[right] # 增加当前右边指针的数字/字符的求和/计数
        //         while 区间[left, right]不符合题意：# 此时需要一直移动左指针，直至找到一个符合题意的区间
        //             sums -= nums[left] # 移动左指针前需要从counter中减少left位置字符的求和/计数
        //             left += 1 # 真正的移动左指针，注意不能跟上面一行代码写反
        //         # 到 while 结束时，我们找到了一个符合题意要求的 子数组/子串
        //         res = max(res, right - left + 1) # 需要更新结果
        //         right += 1 # 移动右指针，去探索新的区间
        //     return res
        // 以右指针作为驱动，拖着左指针向前走。右指针每次只移动一步，
        // 而左指针在内部 while 循环中每次可能移动多步。
        // 右指针是主动前移，探索未知的新区域；
        // 左指针是被迫移动，负责寻找满足题意的区间。
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < k; ++i){// 看第一个窗口
            sum += nums[i];
        }
        int res = sum;             // 暂存第一个窗口sum为最大
        for(int i = k; i < n; ++i){// 窗口向后移 每次一位 便要加上新窗口加的一位 去掉旧窗口的一位（滑动）
            sum = sum + nums[i] - nums[i - k];
            res = max(res, sum);
        } 
        return (double)res/k;
    }
};
// @lc code=end

