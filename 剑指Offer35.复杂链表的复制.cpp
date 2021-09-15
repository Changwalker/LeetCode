#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p = head;

        //创建复制的节点并将其插入到被复制的节点后面
        while(p != NULL){
            Node* newNode = new Node(p->val);
            newNode->next = p->next;
            p->next = newNode;
            p = newNode->next; // 下一个结点
        }

        //复制random
        p = head;
        while(p != NULL){
            if(p->random == NULL)
                p->next->random = NULL;
            else
                p->next->random = p->random->next; //注意是random->next？
            p = p->next->next;
        }

        //创建复制的链表并且将原来的链表恢复
        Node *dummy = new Node(0);
        Node *q = dummy;
        p = head;
        while(p != NULL){
            q->next = p->next;
            p->next = p->next->next;
            p = p->next;
            q = q->next;
        }
        return dummy->next;
    }
};