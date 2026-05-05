#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// basically you would be needing a 2 pointer approach here like you would be needing to keep a start , end for printing the first and 
// printing the total size
class queue_implementation_using_array {
    // declaring size and also the array
    public:
        int size; int *arr; int start; int end; int size_of_queue;

        void set_size(int n) {
            size = n; arr = new int[n];
            start = -1; end = -1; size_of_queue = 0;
        }

        void push(int x) {
            if (start == -1 && end == -1) {
                start ++; end ++;
                arr[start] = x; 
                size_of_queue ++;
            }
            else if (size_of_queue < size) {
                // basically if we would be having more elements still we would be wanting them in the queue as pop operations have happened
                // more
                if (end == size) end = 0;
                
                end ++;
                arr[end] = x;
                size_of_queue ++;
            }   
            else {
                cout << "No elements can be inserted inside the queue ";
            }
    }
    void pop() {
        if (size_of_queue == 0) {
            cout << "No elements to pop " << endl;
        }
        else {
            if (start == size) start = 0;
            start ++;
            size_of_queue --;
        }
    }
    void print_size() {
        cout << size_of_queue << endl;
    }
    void top() {
        if (size_of_queue == 0) {
            cout << "Stack is empty " << endl;
        }
        else cout << arr[start] << endl;
    }

};
void solve() {
    queue_implementation_using_array q;
    q.set_size(4);
    q.push(1);
    q.push(2);
    q.pop();
    q.pop();
    q.pop();
    q.push(3);
    q.push(4);
    q.pop();
    q.top();
    q.print_size();
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
