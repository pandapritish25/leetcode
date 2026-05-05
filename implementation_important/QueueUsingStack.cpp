#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> qu;
    MyStack() {
        
    }
    
    void push(int x) {
        if (qu.size() == 0) {
            qu.push(x);
        }
        else {
            qu.push(x);
            for (int i = 0; i < qu.size() - 1; i++) {
                qu.push(qu.front());
                qu.pop();
            }
        }
    }
    
    int pop() {
        if (qu.size() != 0) {
            int x1 = qu.front();
            qu.pop();
            return x1;
        }
        return 0;
    }
    
    int top() {
        if (qu.size() != 0) return qu.front();
        return 0;
    }
    
    bool empty() {
        if (qu.size() == 0) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */