#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        recur(head);        
        return res;
    }
    void recur(ListNode *head){
        if(head == NULL) return ;
        recur(head->next);
        res.push_back(head->val);
    }
};