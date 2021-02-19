/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//   };

class Solution {
public:
    // 存储父节点，从p q向上跳，记录已访问过的结点，若碰到已访问过结点 则为最近公共祖先
    // 从根节点开始遍历整棵二叉树，用哈希表记录每个节点的父节点指针。
    // 从 p 节点开始不断往它的祖先移动，并用数据结构记录已经访问过的祖先节点。
    // 同样，我们再从 q 节点开始不断往它的祖先移动，如果有祖先已经被访问过，即意味着这是 p 和 q 的深度最深的公共祖先，即 LCA 节点。
    unordered_map<int,TreeNode*> f;
    unordered_map<int,bool> vis;
    void dfs(TreeNode *root){ // 构建每个结点的父节点
        if(root->left != NULL){
            f[root->left->val] = root;
            dfs(root->left);
        }
        if(root->right != NULL){
            f[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        f[root->val] = NULL;
        dfs(root);
        while(p){
            vis[p->val] = true; // 该点已访问
            p = f[p->val]; // 向上移动
        }
        while(q){
            if(vis[q->val]) return q; // 若该点已访问 则该点为最近公共祖先
            q = f[q->val]; // 向上移动
        }
        return NULL;
    }
};
// @lc code=end

