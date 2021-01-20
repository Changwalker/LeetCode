/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int lc = 0, rc = 0;
        dfs(res, "" , n, lc, rc);
        return res;
    }
    void dfs(vector<string> &res, string path, int n, int lc, int rc){
        if(rc > lc || lc > n || rc >n) return;//右括号数大于左括号数||括号数大于n
        if(lc == rc && lc == n){              //出口:左右均为n个
            res.push_back(path);
            return;
        }
        dfs(res, path + '(' , n ,lc + 1 ,rc); //向左
        dfs(res, path + ')' , n ,lc , rc + 1);//向右
    }
};
// @lc code=end

