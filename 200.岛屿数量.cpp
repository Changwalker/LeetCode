/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int nr = grid.size();   // 行数
        int nc = grid[0].size();// 列数
        grid[r][c] = '0';       //每个搜索到的 1 都会被重新标记为 0
        if(r - 1 >= 0 && grid[r-1][c] == '1')
            dfs(grid, r - 1, c);
        if(r + 1 < nr && grid[r+1][c] == '1')
            dfs(grid, r + 1, c);
        if(c - 1 >= 0 && grid[r][c-1] == '1')
            dfs(grid, r, c - 1);
        if(c + 1 < nc && grid[r][c+1] == '1')
            dfs(grid, r, c + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        // DFS
        int nr = grid.size(); // 行数
        if(!nr)
            return 0;
        int nc = grid[0].size();// 列数
        int num_islands = 0;
        for(int i = 0; i < nr; ++i){
            for(int j = 0; j < nc; ++j){
                if(grid[i][j] == '1'){
                    num_islands++;// 最终岛屿的数量就是进行深度优先搜索的次数。
                    dfs(grid, i, j);
                }
            }
        }
        return num_islands;
    }
};
// @lc code=end

