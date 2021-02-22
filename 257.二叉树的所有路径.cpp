/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right; 
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };

class Solution {
public:
    void dfs(TreeNode *root, string path, vector<string>& paths){
        if(root){
            path += to_string(root->val);
            if(root->left == NULL && root->right == NULL){
                paths.push_back(path);
            }
            else{
                path += "->";
                dfs(root->left, path, paths);
                dfs(root->right, path, paths);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};
// @lc code=end

