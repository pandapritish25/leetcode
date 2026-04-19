//https://leetcode.com/problems/factorial-trailing-zeroes/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int trailingZeroes(int n) {
    int ans = 0;
    for (int i = 1; i < 9; i++) {
        int ans1 = pow(5 , i); ans = ans + (n / ans1);
    }
    return ans;
}
void solve() {
    int n; cin >> n;
    cout << trailingZeroes(n) << endl;

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

