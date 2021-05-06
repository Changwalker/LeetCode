/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> arr;
        int n = encoded.size() + 1;
        arr[0] = first;
        for(int i = 1; i < n; ++i){ // ^ ——按位异或
            arr[i] = arr[i - 1] ^ encoded[i - 1];
        }
        return arr;
    }
};
// @lc code=end

