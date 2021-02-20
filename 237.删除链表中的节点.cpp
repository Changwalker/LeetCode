/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val; // node的后继结点复制到当前结点node上
        node->next = node->next->next;// 删去node的后继结点
    }
};
// @lc code=end

