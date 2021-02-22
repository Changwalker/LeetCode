#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
//  pop操作需要分类一下：
//  1.如果stack2为空，那么需要将stack1中的数据从顶到底压入stack2中，然后在对stack2进行pop，
//  2.如果stack2不为空，直接pop就ok。（存有之前的已压入stack2的“部分队首” 要先出队）
        
    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};