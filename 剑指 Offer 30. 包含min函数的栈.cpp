/*
    定义栈的数据结构，
    请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
    调用 min、push 及 pop 的时间复杂度都是 O(1)。

    思路：利用辅助栈
*/
#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> stk, mins;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        stk.push(x);
        if(mins.empty() || x <= mins.top()){
            mins.push(x);
        }
    }
    
    void pop() {
        if(stk.top() == mins.top())
            mins.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return mins.top();
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */