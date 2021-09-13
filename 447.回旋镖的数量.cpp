/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

// 对于每个回旋镖三元组而言，本质上我们在统计给定 i 的情况下，
// 与 i 距离相等的 (j, k)(j,k) 组合个数为多少。

// 我们可以使用哈希表进行预处理，
// 在统计以 i 为三元组第一位的回旋镖个数前，先计算出 ii 和其余点的距离，
// 并以 { 距离 : 个数 } 的形式进行存储，然后分别对所有的距离进行累加计数。

// 题目所描述的回旋镖可以视作一个 V 型的折线。
// 我们可以枚举每个 points[i]，将其当作 V 型的拐点。
// 设 points 中有 m 个点到 points[i] 的距离均相等，
// 我们需要从这 m 点中选出 2 个点当作回旋镖的 2 个端点，
// 由于题目要求考虑元组的顺序，因此方案数即为在 m 个元素中选出 2 个不同元素的排列数，即：
//    A(m,2)=m⋅(m−1)
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for(int i = 0; i < n; ++i){
            unordered_map<int, int> mp; // 统计其余点和i距离
            for(int j = 0; j < n; ++j){
                if(i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int dist = dx * dx + dy * dy;
                mp[dist] ++;
            }
            for(auto [d, cnt] : mp){ // 遍历哈希表方法
                ans += cnt*(cnt - 1);                
            }
        }
        return ans;
    }
};
// @lc code=end

