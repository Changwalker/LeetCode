/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // 所以对于任意一条垂线，其穿过的砖块数量加上从边缘经过的砖块数量之和是一个定值，即砖墙的高度。
        // 问题可以转换成求「垂线穿过的 "砖块边缘" 数量的 最大值」
        // 用砖墙的高度减去该最大值即为答案

        // 具体地，我们遍历砖墙的每一行，
        // 对于当前行，我们从左到右地扫描每一块砖，
        // 使用一个累加器记录当前砖的右侧边缘到砖墙的左边缘的距离，
        // 将除了最右侧的砖块以外的其他砖块的右边缘到砖墙的左边缘的距离加入到哈希表中。
        // 最后我们遍历该哈希表，找到出现次数最多的砖块边缘，
        // 这就是垂线经过的砖块边缘，
        unordered_map<int, int> mp;
        int max_value = 0;
        for(auto w : wall){
            int right_pos_of_line = 0;
            int n = w.size();
            for(int i = 0; i < n - 1; ++i){
                right_pos_of_line += w[i];
                mp[right_pos_of_line]++;
                max_value = max(max_value, mp[right_pos_of_line]);
            }
        }
        // 而该垂线经过的(最少)砖块数量即为
        // 砖墙的高度 减去 该垂线经过的砖块边缘的数量。
        return wall.size() - max_value;
    }
};
// @lc code=end

