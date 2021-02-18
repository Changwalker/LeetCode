/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start

//   struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode *fast = head, *slow = head;
        ListNode *pre = head, *prepre = NULL;
        while(fast != NULL && fast->next != NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            pre->next = prepre;
            prepre = pre;
        }
        //1 2 3 4 5 6 偶数时 fast指向空(末尾结点的后一个即NULL) slow指向后半第一个 不动
        //1 2 3 4 5 奇数时 结束后slow指向中间元素 应当修改为指向中间元素后一个
        if(fast != NULL){     
            slow = slow->next;
        }
        while(pre != NULL && slow != NULL){
            if(pre->val != slow->val){
                return false;
            }
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};
// @lc code=end

