/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start

//   Definition for a binary tree node.
//  Definition for a binary tree node.
#include<bits/stdc++.h>
using namespace std;

// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; ++i){
                TreeNode *p = q.front();
                q.pop();
                if(p->left) 
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end

