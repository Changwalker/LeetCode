/*
 * @lc app=leetcode.cn id=1734 lang=cpp
 *
 * [1734] 解码异或后的排列
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int total = 0;
        for(int i = 1; i <= n; i++){
            total ^= i;
        }
        int odd = 0;
        for(int i = 1; i < n - 1; i += 2){
            odd ^= encoded[i];
        }
        vector<int> perm(n);
        perm[0] = total ^ odd;
        for(int i = 0; i < n - 1; i++){
            perm[i + 1] = perm[i] ^ encoded[i];
        }
        return perm;
    }
};
// @lc code=end

