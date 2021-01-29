/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 行列均从0开始 第n行第m个数为C(n,m) (n下) 第4行第2个为C(4,2)=6
        vector<vector<int>> res(numRows);
        for(int i = 0; i < numRows; ++i){
            res[i].resize(i+1);             // 第i行元素个数为i+1个
            res[i][0] = res[i][i] = 1;      // 每行首尾为1
            for(int j = 1; j < i; ++j){     // 计算除了首尾的其他元素
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j]; // 上行对应两个加和
            }
        }
        return res;
    }
};
// @lc code=end

