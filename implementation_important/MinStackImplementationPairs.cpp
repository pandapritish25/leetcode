#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    int min1 = INT_MAX;
    stack<pair<int,int>> st;
    MinStack() {
    }
    
 void push(int val) {
    if (st.empty()) {
        st.push({val, val});
    } else {
        st.push({val, min(val, st.top().second)});
    }
}
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
        else {
            min1 = INT_MAX;
        }
    }
    
    int top() {
        if (!st.empty()) {
            pair<int,int> curr_ans = st.top();
            return curr_ans.first;
        }
        return 0;
    }
    
    int getMin() {
        if (!st.empty()) {
            pair<int,int> curr_ans = st.top();
            return curr_ans.second;
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