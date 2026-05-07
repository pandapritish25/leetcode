#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void solve() {
    int n; cin >> n;
    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];
    }
    // thus we would be doing the top and down approach means suppsose top is a celebrity means he wont be knowing down 
    // at the end top and down should be at the same place , thus I can say that the top and down should be at the same place
    // then only you can have top and down in place

    // so for this reason we would be taking this
    int top = 0 , down = n - 1;
    while (top < down) {
        if (arr[top][down] == 1) {
            top = top + 1;
        }
        else if (arr[down][top] == 1) {
            down = down - 1;
        }
        else {
            top = top + 1;
            down = down - 1;
        }
        if (top > down) {
            break;
        }
    }

    if (top > down) {
        cout << "No celebrity" << endl;
        return;
    }
    if (top == down) {
        int ok = 1;
        // final check for the elements
        for (int i = 0; i < n; i++) {
            if (i == 1) continue;
            if (arr[i][top] !=  1) {
                ok = 0; break;
            }
            if (arr[top][i] != 0) {
                ok = 0; break;
            }
        }

        if (ok) {
            cout << top << endl;
        } 
        else {
            cout << "No celebrity" << endl;
        }
    }   
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
