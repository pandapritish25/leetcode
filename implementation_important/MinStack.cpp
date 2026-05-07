#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

struct minstack {
    stack<int> st; int min1 = INT_MAX;

    void push(int x) {
        if (st.empty()) {
            st.push(x);
            min1 = x;
        }
        else if (x < min1) {
            st.push(2 * x - min1);
            min1 = x;
        }
    }

    void pop() {
        if (!st.empty() && st.top() < min1) {
            min1 = 2 * min1 - st.top();
            st.pop();
        }
        else {
            st.pop();
        }
    }

    int top() {
        if (!st.empty() && st.top() < min1) {
            return min1;        }
        else {
            return st.top();
        }
    }

    int get_min() {
        return min1;
    }
};  

void solve() {
    minstack st;
    st.push(12);
    st.push(15);
    cout << st.get_min() << endl;
    cout << st.top() << endl;
    st.push(10);
    cout << st.get_min() << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.get_min() << endl;
    cout << st.top() << endl;
}


signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t --) {
        solve();
    }
}
