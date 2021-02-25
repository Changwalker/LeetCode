/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> temp;
        vector<vector<int>> res;
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                temp.push_back(matrix[i][j]);
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};
// @lc code=end

