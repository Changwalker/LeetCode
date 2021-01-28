/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

//   struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) 
            return 0;
        else if(root->left == nullptr)
            return minDepth(root->right) + 1;
        else if(root->right == nullptr)
            return minDepth(root->left) + 1;
        else
            return min(minDepth(root->left),minDepth(root->right)) + 1;
        // if(root->left == nullptr && root->right == nullptr)
        //     return 1;
        // int min_depth = INT_MAX;
        // if(root->left != nullptr){
        //     min_depth = min(minDepth(root->left), min_depth);
        // }
        // if(root->right != nullptr){
        //     min_depth = min(minDepth(root->right), min_depth);
        // }
        // return min_depth + 1;
    }
};
// @lc code=end

