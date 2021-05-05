/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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

class Solution {
public:
    struct Node{
        int val;
        ListNode *ptr;
        bool operator < (const Node &rhs) const{
            return val > rhs.val;
        }
    } ;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node> q;
        for(auto node : lists){
            if(node)
                q.push({node->val,node});
        }
        ListNode head, *tail = &head;
        while(!q.empty()){
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;

            if(f.ptr->next)
                q.push({f.ptr->next->val,f.ptr->next});
        }
        return head.next;
    }
};
// @lc code=end

