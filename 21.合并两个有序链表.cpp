/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //递归写法   
        //终止条件：当两个链表都为空时，表示我们对链表已合并完成。
        if(l1 == nullptr)//出口
            return l2;
        else if(l2 == nullptr)//出口
            return l1;
        //如何递归：我们判断 l1 和 l2 头结点哪个更小，
        //然后较小结点的 next 指针指向其余结点的合并结果。（调用递归）
        else if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
// @lc code=end

