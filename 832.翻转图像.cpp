/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i = 0; i < A.size(); ++i){
            reverse(A[i].begin(), A[i].end());
            for(int j = 0; j < A[i].size(); ++j){
                A[i][j] = A[i][j] == 0? 1 : 0;
            }
        }
        return A;
    }
};
// @lc code=end

