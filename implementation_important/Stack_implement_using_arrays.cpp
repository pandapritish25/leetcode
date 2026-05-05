#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// implementation of stack using an array
// imagine I know the size of the array before hand , like I know ok this would be my maximum size

class stack_implementation_using_array {
     // taking the input for that size
     // initiate this with a size
    int size; int *arr; int top;
    public : 
        void set_size(int n) {
            size = n; top = -1;
            arr = new int[size];
        }
        void push(int x) {
            if (top == size) {
                cout << "More numbers cant be inserted inside array";
            }
            else {
                top ++; arr[top] = x;
            }
        }
        void pop() {
            if (top == -1) {
                cout << "No elements to pop";
            }
            else {
                top --;
            }
        }
        void print_size() {
            cout << top + 1 << endl;
        }
        void print_top() {
            if (top == -1) {
                cout << "There are no elements in the stack";
            }
            else {
                cout << arr[top] << endl;
            }
        }
};
void solve() {
    stack_implementation_using_array s1;
    s1.set_size(10);
    s1.push(8);
    s1.push(9);
    s1.push(10);
    s1.print_top();
    s1.print_size();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.print_top();
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
