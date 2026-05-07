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

    vector<int> knowme(n, 0);
    vector<int> iknow(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                iknow[i] ++;
                knowme[j] ++;
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (iknow[i] == 0 && knowme[i] == n - 1) {
            ans = i; break;
        }
    }
    cout << ans << endl;
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
