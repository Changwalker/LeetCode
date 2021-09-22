/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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


// 当我们需要构造出 ans[i] 的链表长度时，首先可以先分配 per 的长度，
// 如果已处理的链表长度 + 剩余待分配份数 * per < cnt，
// 说明后面「待分配的份数」如果按照每份链表分配 per 长度的话，会有节点剩余，
// 基于「不能均分时，前面的应当比后面长」原则，
// 此时只需为当前 ans[i] 多分一个单位长度即可。
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* t = head;
        while(t != NULL){
            t = t->next;
            len++;
        }
        // 将链表分割为 k 份（sum 代表已经被处理的链表长度为多少）
        int per = len / k;
        vector<ListNode*> res;
        for(int i = 0, sum = 1; i < k; i++, sum ++){
            res.push_back(head);
            // res[i] = head;
            t = res[i];
            int temp_per = per;
            while(temp_per-- > 1){
                t = t->next;
                sum ++;
            }
            // 当 已处理的链表长度+剩余待分配份数*per<cnt，再分配一个单位长度
            int remain = k - i - 1;
            if(per != 0 && sum + per * remain < len){
                t = t->next;
                sum ++;
            }
            if(t == NULL)
                head = NULL;
            else 
                head = t->next;
            if(t != NULL)
                t->next = NULL;
        }
        return res;
    }
};
// @lc code=end

