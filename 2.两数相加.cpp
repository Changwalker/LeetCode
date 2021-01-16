/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {} 
 *   ——ListNode(int x)函数表示创建一个单独节点，
 *     指向NULL，即创建一个头节点
 * };
 * 对于链表，每一个新的数字产生包括加数l1->val,
 * 加数l2->val,进位tem_r, 只要这三个数全部为零的时候结束，这就是终止条件；
 * 接下来我们需要一个res的链表头作为固定的返回值，
 * 一个代理节点cur作为每次新建节点的指针

 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);//结果表
        ListNode* cur = new ListNode(0);//新建节点
        ListNode* temp_node = new ListNode(0);
        res->next = cur;
        int t = 0;
        while(1)
        {  
            int temp = (l1->val + l2->val + t);
            cur->next =  new ListNode(temp%10);
            cur = cur->next;
            t = temp/10;//进位
            l1 = l1->next;
            l2 = l2->next;
            if(l1==NULL && l2==NULL && t==0 ) break;
            if(l1 == NULL) l1= temp_node;
            if(l2 == NULL) l2= temp_node;
        }
        return res->next->next;
    }//在每一次计算的时候，算一个进位，一个取模值，生成一个节点，更新l1,l2,cur;
};
// @lc code=end

//1 2 9 
//1 7 1
//个位：9+1+0->10->1  十位：2+7+1->10->1 百位：1+1+1->3