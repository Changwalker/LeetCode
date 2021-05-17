/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
    bool isCousins(TreeNode* root, int x, int y) {
        using PTT = pair<TreeNode*, TreeNode*>;
    bool isCousins(TreeNode* root, int x, int y) {
        // 使用队列q来进行bfs
        // 其中pair中，p.first 记录当前结点的指针，p.second 记录当前结点的父结点的指针
        queue<PTT> q;
        q.push({root, nullptr});
        while(!q.empty()) {
            int n = q.size();
            vector<TreeNode*> rec_parent;
            for(int i = 0; i < n; i++) {
                auto [cur, parent] = q.front(); q.pop();
                if(cur->val == x || cur->val == y)
                    rec_parent.push_back(parent);
                if(cur->left) q.push({cur->left, cur});
                if(cur->right) q.push({cur->right, cur});
            }
            // `x` 和 `y` 都没出现
            if(rec_parent.size() == 0)
                continue;
            // `x` 和 `y` 只出现一个
            else if(rec_parent.size() == 1)
                return false;
            // `x` 和 `y` 都出现了
            else if(rec_parent.size() == 2)
                // `x` 和 `y` 父节点 相同/不相同 ？
                return rec_parent[0] != rec_parent[1];
        }
        return false;
    }
};
// @lc code=end

