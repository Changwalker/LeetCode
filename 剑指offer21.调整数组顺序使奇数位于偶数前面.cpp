#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(int& i,int& j, vector<int>& nums){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i < j){
            while(i < j && nums[i]%2 != 0)
                i++;
            while(i < j && nums[j]%2 == 0)
                j--;
            swap(i, j, nums);
        }
        return nums;
    }
};