#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
/*
    假设链表为 n1->n2->...->nk->nk+1->...->nm-1->nm
    现在从nk+1到nm已经反转 ：n1->n2->...->nk->nk+1<-...nm-1<-nm
    
    现在我们正处在nk
    我们希望nk+1的下一节点指向nk
    所以 nk->next->next 指向 nk 
    即nk+1指向nk

    需要注意的是 n1必须指向null，否则会出现环
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* realhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return realhead;
    }
};