/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

// struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; ++i){
                TreeNode *p = q.front();
                q.pop();
                temp.push_back(p->val);
                if(p->left)  
                    q.push(p->left);
                if(p->right) 
                    q.push(p->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

