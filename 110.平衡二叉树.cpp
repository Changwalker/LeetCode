/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int getdepth(TreeNode *root){
        if(root == nullptr) return 0;
        int lh = getdepth(root->left);
        int rh = getdepth(root->right);
        if(lh == -1 || rh == -1 || abs(lh - rh) > 1)
            return -1;
        else 
            return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return getdepth(root) >= 0;
    }
};
// @lc code=end

