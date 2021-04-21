/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, int& last, int& res){
        if(root == nullptr)
            return ;
        inorder(root->left, last, res);
        if(last == -1) //当前为最左结点
            last = root->val;
        else
        {
            res = min(root->val-last,res);
            last = root->val;
        }

        inorder(root->right, last, res);
    }
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX, last = -1;
        inorder(root, last, res);
        return res;
    }
};
// @lc code=end

