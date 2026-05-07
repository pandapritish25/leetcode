#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int trap(vector<int>& height) {
    int l = 0 , r = height.size() - 1;
    int lmax = 0 , rmax = 0;
    int sum = 0;

    while (l < r) {
        if (height[l] <= height[r]) {
            if (height[l] < lmax) {
                sum += (lmax - height[l]);
            }
            else {
                lmax = height[l];
            }
            l ++;
        }
        else {
            if (height[r] < rmax) {
                sum += (rmax - height[r]);
            }
            else {
                rmax = height[r];
            }
            r --;
        }
    }  
    return sum; 
}
void solve() {
    int n; cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) cin >> height[i];
    cout << trap(height) << endl;
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
