/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> s;
    stack<int> min_stack;
public:
    /** initialize your data structure here. */
    // 利用辅助栈：在每个元素 a 入栈时把当前栈的最小值 m 存储起来。
    // 在这之后无论何时，如果栈顶元素是 a，我们就可以直接返回存储的最小值 m。
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        s.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        s.pop();
        min_stack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

