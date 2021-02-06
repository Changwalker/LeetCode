/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        // 加一个虚拟头节点
        ListNode *node = new ListNode(val+1);//取不等于val的数
        node->next = head;
        ListNode *pre = node, *p = head, *del = NULL;
        while(p != NULL){
            if(p->val == val){
                pre->next = p->next;
                del = p;
            }
            else 
                pre = p;

            p = p->next;
            
            if(del != NULL){
                delete del;
                del = NULL;
            }
        }
        // 重点 只有一个结点且值为val时 
        // 删除后无head 要将返回指针指向辅助结点的next.然后删除辅助结点
        ListNode *ret = node->next;
        delete node;
        return ret;


        // 2.递归
        if(head == NULL)
            return NULL;
        head->next = removeElements(head->next, val);
        if(head->val == val){
            return head->next;
        }
        else 
            return head;
    }
};
// @lc code=end

