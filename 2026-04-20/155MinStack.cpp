#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int> st1 , st2;
    MinStack() {
        st1 = stack<int>();st2 = stack<int>();
    }
    
    void push(int val) {
        st1.push(val);
        if (st2.empty()) st2.push(val);
        else if (!st2.empty() && st2.top() >= val) st2.push(val);
    }
    
    void pop() {
        if (!st1.empty() && !st2.empty() && st1.top() == st2.top()) st2.pop();
        if (!st1.empty()) st1.pop();
        
    }
    
    int top() {
        if (!st1.empty()) {
            return st1.top();
        }
        return 0;
    }
    
    int getMin() {
        if (!st2.empty()) {
            return st2.top();
        }
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */