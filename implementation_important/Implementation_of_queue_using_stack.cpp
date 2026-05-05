#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// basically we would be implementing queue using a stack 
// so one point to remember here is that whenever we would be needing to implement a queue from any of data structure , 
// we would be needing something called as multiple things implementation 
// but in case of stacks , we would be needing single implmentation in case of queue , we would be needing multiple implemention
class queue_implementation_using_stack {
    public:
        stack<int> s1; stack<int> s2;
        void push(int x) {
            if (s1.empty()) {
                s1.push(x);
            }
            else {
                while (!s1.empty()) {
                    s2.push(s1.top()); 
                    s1.pop();
                }
                s1.push(x);
                while (!s2.empty()) {
                    s1.push(s2.top()); 
                    s2.pop();
                }
            }
        }
        void pop() {
            if (s1.empty()) {
                cout << "No elements to pop\n";
            }
            else {
                s1.pop();
            }
        }
        void top() {
            if (s1.empty()) {
                cout << "No elements to print top\n";
            }
            else {
                cout << s1.top() << endl;
            }
        }
        void print_size() {
            cout << s1.size() << endl;
        }
};
void solve() {
    queue_implementation_using_stack qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.print_size();
    qu.pop();
    qu.pop();
    qu.top();
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
