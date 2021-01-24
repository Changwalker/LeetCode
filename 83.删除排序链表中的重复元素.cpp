/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next ==NULL)
            return head;
        ListNode *p;
        for(p = head; p->next != NULL;){
            if(p->val == p->next->val)
                p->next = p->next->next;
            else 
                p = p->next;
        }
    return head;
    }    
};
// @lc code=end

