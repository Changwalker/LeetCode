
// 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
// 第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 输出：
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
// 双端队列0:[] [3] 1:[9,20] [15,7,9] 2:[15,7] [7] [] 
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        deque<TreeNode*> dq;
        int layer = 0;// 初始层为0层
        dq.push_back(root);
        while(!dq.empty()){
            int size = dq.size();
            vector<int> tmp;
            while(size--){
                if(layer & 1){
                    TreeNode* node = dq.back();
                    dq.pop_back();
                    tmp.push_back(node->val);
                    if(node->right) dq.push_front(node->right);
                    if(node->left) dq.push_front(node->left);
                }
                else{
                    TreeNode* node = dq.front();
                    tmp.push_back(node->val);
                    dq.pop_front();
                    if(node->left) dq.push_back(node->left);
                    if(node->right) dq.push_back(node->right);
                }
            }
            ++layer;
            res.push_back(tmp);
        }
        return res;
    }
};