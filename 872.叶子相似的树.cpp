/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    void judge(TreeNode* root, vector<int>& leaf){
        if(root->left == NULL && root->right == NULL){
            leaf.push_back(root->val);
        }
        else{
            if(root->left)
                judge(root->left, leaf);
            if(root->right)
                judge(root->right, leaf);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> lseq_1, lseq_2;
        if(root1){
            judge(root1, lseq_1);
        }
        if(root2){
            judge(root2, lseq_2);
        }
        return lseq_1 == lseq_2;
    }
};
// @lc code=end

