/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    // BST的中序遍历是升序的，因此本题等同于根据中序遍历的序列恢复二叉搜索树。
    // 因此我们可以以升序序列中的任一个元素作为根节点，
    // 以该元素左边的升序序列构建左子树，以该元素右边的升序序列构建右子树，
    // 这样得到的树就是一棵二叉搜索树啦～ 又因为本题要求高度平衡，
    // 因此我们需要选择升序序列的中间元素作为根节点
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
    TreeNode* dfs(vector<int>& nums, int low, int high){
        if(low > high)
            return nullptr;
        // 总是选择中间位置左边的数字作为根节点
        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        // 递归的构建 root 的左子树与右子树。
        root->left  = dfs(nums, low, mid - 1);
        root->right = dfs(nums, mid + 1, high);
        return root;
    }
};
// @lc code=end

