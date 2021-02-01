/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        // 1.哈希表
        // if(head == NULL || head->next == NULL)
        //     return false;
        // unordered_set<ListNode*> s;
        // while(head != NULL){
        //     if(s.count(head)){
        //         return true;
        //     }
        //     s.insert(head);
        //     head = head->next;
        // }
        // return false;

        // 2.快慢指针 （龟兔赛跑算法）
        // 为什么我们要规定初始时慢指针在位置 head?
        // 观察下面的代码，我们使用的是 while 循环，循环条件先于循环体。
        // 如果我们将两个指针初始都置于 head，那么 while 循环就不会执行。
        // 因此，我们可以假想一个在 head 之前的虚拟节点，
        // 慢指针从虚拟节点移动一步到达 head，快指针从虚拟节点移动两步到达 head.next，
        // 这样我们就可以使用 while 循环了。
        // 或者用do-while 可直接令快慢指针指向head
        if(head == NULL || head->next == NULL)
            return false;
        ListNode* slow = head, *fast = head->next;
        while(slow != fast){                       // 相遇时跳出 返回true
            if(fast == NULL || fast->next == NULL) // 链表有尾指针 返回false
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true; 
    }
};
// @lc code=end

