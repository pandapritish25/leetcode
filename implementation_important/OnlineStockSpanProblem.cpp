#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        i ++;
        if (!st.empty() && st.top().first <= price) {
            while (!st.empty() && st.top().first <= price) {
                st.pop();
            }   
        }
        if (st.empty()) {
            st.push({price , i});
            return i;
        }
        if (!st.empty() && st.top().first > price) {
            int ans1 = st.top().second;
            st.push({price , i}); return i - ans1;
        }
        return 0;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */