/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(TreeNode* root, int sum){
        if(root == NULL) 
            return ;
        path.push_back(root->val);
        sum -= root->val;
        if(root->left == NULL && root->right == NULL && sum == 0)
            res.push_back(path);
        
        dfs(root->left, sum);
        dfs(root->right, sum);
        // 回溯，在当前节点时path数组记录当前状态要把这个节点存进来，
        // 现在这个节点的子树已经遍历完了，要把它拿走
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
};
// @lc code=end

