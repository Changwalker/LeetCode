#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end()))
            return true;
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n - 1; ++i){
            // 若可调转后有序 则只有一次下落 例345 12 ; 3 12
            if(nums[i] > nums[i + 1])
                cnt ++;
            if(cnt > 1) return false;
        }
        // 数组作为环 检查最后一个元素是否小于等于第一个元素
        return nums[n-1] <= nums[0];
    }
};