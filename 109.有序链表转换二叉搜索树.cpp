/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);

        //快慢指针
        ListNode *p = head, *q = head, *pre =NULL;
        while(q != NULL && q->next == NULL){
            pre = p;
            p = p->next;      //p走一步 p指向mid位置
            q = q->next->next;//q走两步 q指向末尾
        }
        // 这句话是用来切割链表的，递归的跳出条件即为空。 
        // 否则 root.left = sortedListToBST(head); 会一直往后面到链表最后面。
        pre->next == NULL;
        
        // 以升序链表的中间元素作为根节点 root，递归的构建 root 的左子树与右子树。
        TreeNode* root = new TreeNode(p->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(p->next);
        return root;
    }
};
// @lc code=end

