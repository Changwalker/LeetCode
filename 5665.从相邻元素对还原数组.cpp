/*
存在一个由 n 个不同元素组成的整数数组 nums ，但你已经记不清具体内容。
好在你还记得 nums 中的每一对相邻元素。

给你一个二维整数数组 adjacentPairs ，大小为 n - 1 ，
其中每个 adjacentPairs[i] = [ui, vi] 表示元素 ui 和 vi 在 nums 中相邻。

题目数据保证所有由元素 nums[i] 和 nums[i+1] 组成的相邻元素对都存在于 adjacentPairs 中，
存在形式可能是 [nums[i], nums[i+1]] ，也可能是 [nums[i+1], nums[i]] 。
这些相邻元素对可以 按任意顺序 出现。

返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。

// 示例 1：

// 输入：adjacentPairs = [[2,1],[3,4],[3,2]]
// 输出：[1,2,3,4]
解释：数组的所有相邻元素对都在 adjacentPairs 中。
特别要注意的是，adjacentPairs[i] 只表示两个元素相邻，并不保证其 左-右 顺序。

*/
/*对于样例1：
输入：adjacentPairs = [[2,1],[3,4],[3,2]]
输出：[1,2,3,4]
哈希表  g
key  value
1     2
2     1，3
3     2，4
4     3
可以看到，除了数组中的两个端点，其他点在哈希表中都对应两个 value ，
之后，我们可以利用这个性质找到这两个端点其中的一个，
然后从这个端点开始，借助哈希表依次找到所有相邻的点，并加入答案数组，直到数组长度为 n 。

比如对于样例我们从 1 开始，找到 2，再从 2 开始，找到 1，
1 已经被使用了，再找 3，再从 3 开始，找到 2，
2 已经被使用了，我们再找4，此时数组长度已经为 n 了，我们返回答案数组[1，2，3，4]。

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> path;
    unordered_map<int, vector<int>> g;

    void dfs(int u, int father){
        path.push_back(u);
        for(int x: g[u])
            if(x != father)
                dfs(x,u);
    }

    vector<int> restoreArray(vector<vector<int>>& ap) {
        unordered_map<int, int> cnt;
        for(auto& e:ap){
            int a = e[0], b = e[1];//取出数对
            g[a].push_back(b), g[b].push_back(a);
            cnt[a] ++, cnt[b] ++;
        }
        int root = 0;
        for(auto [k, v]: cnt){//找根
            if(v == 1){
                root = k;
                break;
            }
        }
        dfs(root, -1);
        return path;
    }
};