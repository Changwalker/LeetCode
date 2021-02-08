/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int res = 1;
        int left = 0, right = 0;
        while(right < n - 1){
            if(left == right){
                // left 和 right 相等时：
                // 只要arr[right] != arr[right+1]，就可以将 right右移一个单位；
                // 否则，left 和 right 都要同时右移。
                if(arr[left] == arr[left + 1])
                    left++;
                right++;
            }
            else{
                if(arr[right - 1] < arr[right] && arr[right] > arr[right + 1])
                    right++;
                else if(arr[right - 1] > arr[right] && arr[right] < arr[right + 1])
                    right++;
                else 
                    left = right;// 大小归为1
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
// @lc code=end

