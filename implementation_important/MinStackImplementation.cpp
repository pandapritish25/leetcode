#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

class MinStack {
public:
    stack<long long> st;
    int curr_min = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            curr_min = val;
        }
        else {
            if (val <= curr_min) {
                long long ans1 = (2 * val - curr_min);
                st.push(ans1);
                curr_min = val;
            }
            else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if (!st.empty()) {
            if (st.top() < curr_min) {
                curr_min = 2 * curr_min - st.top();
                st.pop();
            }
            else {
                st.pop();
            }
        }
        
    }
    
    int top() {
        if (!st.empty()) {
            if (st.top() < curr_min) {
                int top1 = 2 * curr_min - st.top();
                return top1;
            }
            else {
                return st.top();
            }
        }
        return 0;
    }
    
    int getMin() {
        if (st.empty()) return 0;
        return curr_min;
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