/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        int t;
        while((p1 >= 0) || (p2 >= 0)){
            // 从后往前遍历 大的插入nums1
            // nums1为空数组
            if(p1 == -1){
                t = nums2[p2--];
            } 
            // nums2为空数组
            else if(p2 == -1){
                t = nums1[p1--];
            }
            else if (nums1[p1] > nums2[p2]){
                t = nums1[p1--];
            }
            else {
                t = nums2[p2--];
            }
            nums1[p--] = t;
        }
    }
};
// @lc code=end

