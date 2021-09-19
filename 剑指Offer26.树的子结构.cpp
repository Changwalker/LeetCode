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
    // 递归出口：
    // 若B先深度搜索完，说明前面的值都匹配正确，return true
    // 若A先深度搜索完，说明越界（B树的结点比A树还多），return false

    // 对于isSubStructure
    // 若以从A, B根结点同时出发开始的dfs匹配成功，return true
    // 若失败，则以A的左右子树进行递归，即对A的dfs起点更换
    bool isSubStructure(TreeNode* A, TreeNode* B) {
		// 1. 如果A和B有一个是NULL，则返回false
		// 2. 对A和B进行迭代搜索，返回结果
        // 3. 对A的左子树和B进行迭代搜索，返回结果
        // 4. 对A的右子树和B进行迭代搜索，返回结果
		return (A && B) && (recur(A,B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
	}
	
	bool recur(TreeNode* A, TreeNode* B) {
        // 如果B为null，则B是A的子树，因为如果B不是A的子树的话，前面迭代的时候已经返回false了，程序运行不到这里返回不了true。
        // 这里其实是迭代的终止条件
		if(!B) return true;
        // 当A为null，或者比较A和B是否一样，一样则继续迭代，否则不需要迭代了，直接返回false结果
		if(!A || A->val != B->val) return false;
        // 树的迭代循环
        // 比较A和B的左子树和右子树 若A有结点值与B有结点值不相等，匹配失败，return false
		return recur(A->left, B->left) && recur(A->right, B->right);
    }
};