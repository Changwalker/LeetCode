/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
//  Definition for a binary tree node.
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
    bool judge(TreeNode *left, TreeNode *right){
        if(left == right)                //左右相同
            return true;
        if(left == NULL || right == NULL)//左空或右空（已排除left==right==NULL）
            return false;
        return  (left->val == right->val)&&
                (judge(left->left, right->right))&&
                (judge(left->right, right->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) 
            return true;
        else {
            return judge(root->left, root->right);
        }
    }
};
// @lc code=end

