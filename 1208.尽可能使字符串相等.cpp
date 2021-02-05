/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
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

        // 对于 s = "abcd", t = "bcdf", cost = 3 而言，
        // 我们使用 diff[i] 表示从 s[i]  转成 t[i] 的开销，
        // 那么 costs = [1, 1, 1, 2] 。由于 maxCost = 3， 
        // 所以最多允许其前面三个字符进行转换

        int n = s.size();
        vector<int> diff(n, 0);// 大小为n 初值为0
        for(int i= 0; i < n; ++i){
            diff[i] = abs(s[i] - t[i]);
        }
        int maxLength = 0;
        int left = 0, right = 0;
        int sum = 0;
        while(right < n){
            sum += diff[right];
            while(sum > maxCost){ // 寻找符合条件 左指针右移
                sum -= diff[left];
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};
// @lc code=end

