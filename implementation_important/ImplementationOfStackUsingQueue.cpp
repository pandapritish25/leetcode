#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// implement stack using queue
class stack_implementation_using_queue {
    // basically take a stack and queue
    public:
        queue<int> qu;
        void push(int x) {
            if (qu.size() == 0) {
                qu.push(x);
            }
            else {
                int curr_size = qu.size();
                qu.push(x); 
                for (int i = 0; i < curr_size; i++) {
                    int top_element = qu.front();
                    qu.pop(); qu.push(top_element);
                }
            }
        }
        void pop() {
            if (qu.size() != 0) {
                qu.pop();
            }
            else {
                cout << "No elements inside the queue\n";
            }
        }
        void print_size() {
            cout << qu.size() << endl;
        }
        void print_top() {
            if (qu.size() == 0) {
                cout << "No elements inside the queue\n";
            }
            else {
                cout << qu.front() << endl;
            }
        }
};
void solve() {
    stack_implementation_using_queue st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(2);
    st.push(10);
    st.pop();
    st.print_size();
    st.print_top();
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
