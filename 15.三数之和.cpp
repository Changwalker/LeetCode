/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 3) return{}; //特判
        sort(nums.begin() ,nums.end());

        for(int i = 0; i < n; i ++){
            if(nums[i] > 0) return res;// 第一个数大于 0，后面都是递增正数，不可能相加为零了
            
            if(i > 0 && nums[i] == nums[i - 1]) // 去重：如果此数已经重复 选取过，跳过
                continue;

            int l = i + 1, r = n -1; // 双指针在i之后的区间中寻找另外两个数
            while(l < r){
                if(nums[i] + nums[l] + nums[r] > 0){
                    r--;
                }
                else if(nums[i] + nums[l] + nums[r] < 0){
                    l++;
                }
                else{
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    // 去重：使第二个数和第三个数不重复
                    while(l < r && nums[l] == nums[l - 1]) l++;
                    while(l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }        
        return res;
    }
};
// @lc code=end
// vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> res;
//         int n = nums.size();
//         sort(nums.begin() ,nums.end());
//         int l = 0, r = n - 1;
//         while(l < r){
//             vector<int> t;
//             if(nums[l] + nums[r] <= 0){
//                 for(int i = r - 1; i > l; i--){
//                     if(nums[l] + nums[r] + nums[i] == 0){
//                         t.push_back(nums[l]);
//                         t.push_back(nums[r]);
//                         t.push_back(nums[i]);
//                         res.push_back(t);
//                     }
//                 }
//             }
//             else if(nums[l] + nums[r] > 0){
//                 for(int i = l + 1; i < r; i++){
//                     if(nums[l] + nums[r] + nums[i] == 0){
//                         t.push_back(nums[l]);
//                         t.push_back(nums[r]);
//                         t.push_back(nums[i]);
//                         res.push_back(t);
//                     }
//                 }
//             }
//         }
//         return res;
//      }