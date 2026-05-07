#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int maxArea(vector<int>& height) {
    int n = height.size(); int l = 0; int r = n - 1;
    int max1 = 0;

    while (l < r) {
        int area = min(height[l] , height[r]) * (r - l);
        max1 = max(max1 , area);
        if (height[l] <= height[r]) l ++;
        else r --;
    }
    return max1;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans1 = maxArea(v);
    cout << ans1 << endl;
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
