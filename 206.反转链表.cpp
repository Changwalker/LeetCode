/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head, *pre = NULL;
        while(p){
            ListNode *next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return pre;
    }
};
// @lc code=end

