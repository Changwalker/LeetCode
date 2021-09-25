/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* dummy = new Node();
        dummy->next = head;
        while(head != NULL){
            if(head->child == NULL)
                head = head->next;
            else{
                Node* tmp = head->next;
                Node* chead = flatten(head->child);

                head->next = chead;
                chead->prev = head;
                head->child = NULL;
                while(head->next != NULL) head = head->next;
                head->next = tmp;
                if(tmp != NULL) tmp->prev = head;
                head = tmp;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

