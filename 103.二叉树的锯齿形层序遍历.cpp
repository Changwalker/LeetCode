/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;


// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode *> q;
        // 维护一个变量 \textit{isOrderLeft}isOrderLeft 记录是从左至右还是从右至左的：
        // 如果从左至右，我们每次将被遍历到的元素插入至双端队列的末尾。
        // 如果从右至左，我们每次将被遍历到的元素插入至双端队列的头部。
        bool isOrderLeft = true;
        q.push(root);
        while(!q.empty()){
            deque<int > dq;//双端队列
            int n = q.size();
            for(int i = 0; i < n; ++i){
                TreeNode *p = q.front(); 
                q.pop();
                if(isOrderLeft)
                    dq.push_back(p->val);
                else
                    dq.push_front(p->val);
                if(p->left) 
                    q.push(p->left);
                if(p->right) 
                    q.push(p->right); 
            }
            ans.emplace_back(vector<int>{dq.begin(),dq.end()});
            isOrderLeft = !isOrderLeft; //标志位转换
        }
        return ans;
    }
};
// @lc code=end

