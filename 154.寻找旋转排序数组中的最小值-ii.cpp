/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            // 如果中间位置的值小于最右面的值，说明从mid到r可能在递增，突变最小值可能在右面
            if(nums[mid] < nums[r]){
                r = mid;
            }
            // 如果中间位置的值大于最右面的值，说明突变最小值在mid的右面
            else if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            else if(nums[mid] == nums[r]){
                r--;
            }
        }
        return nums[r];
    }
};
// @lc code=end

