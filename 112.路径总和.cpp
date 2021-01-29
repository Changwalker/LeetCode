/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 1.递归：归纳成：
        // 询问是否存在从当前节点 root 到叶子节点的路径，满足其路径和为 sum。
        // 假定从根节点到当前节点的值之和为 val，
        // 我们可以将这个大问题转化为一个小问题：
        // 是否存在从当前节点的子节点到叶子的路径，满足其路径和为 sum - val。

        if(root == NULL) 
            return false;
        if(root->left == NULL && root->right == NULL)
            return targetSum == root->val;
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
        
        // 2.BFS 双队列
        // 使用两个队列，分别存储将要遍历的节点，以及根节点到这些节点的路径和即可。
        
        // if(root == NULL)
        //     return false;
        // queue<TreeNode *> que_node;
        // queue<int> que_val;
        // que_node.push(root);
        // que_val.push(root->val);
        // while(!que_node.empty()){
        //     TreeNode *p = que_node.front();
        //     int temp = que_val.front();
        //     que_node.pop();
        //     que_val.pop();
        //     if(p->left == NULL && p->right == NULL){ //叶节点
        //         if(temp == targetSum) return true;   //存在时 出口
        //         continue;
        //     }
        //     if(p->left != NULL){                     //左非空
        //         que_node.push(p->left);
        //         que_val.push(p->left->val + temp);
        //     }
        //     if(p->right != NULL){                    //右非空
        //         que_node.push(p->right);
        //         que_val.push(p->right->val + temp);
        //     }
        // }
        // return false;
    }
};
// @lc code=end

