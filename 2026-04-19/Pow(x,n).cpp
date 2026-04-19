//https://leetcode.com/problems/powx-n/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

double myPow(double x, int n) {
    if (n == 0) return 1.0;
    if (n == 1) return x;
    if (x == 1) return 1.0;
    if (x == 0) return 0.0;


    if (x == -1) {
        if (n % 2 == 0) return 1.0;
        else return -1.0;
    }

    if (n == INT_MIN) return 0;

    if (n < 0) x = (1 / x) * 1.0;
    n = abs(n);

    double ans = 1;
    while (1) {
        if (n == 0) return ans * 1.0;
        if (n % 2 == 1) ans = ans * x * 1.0;
        x = x * x * 1.0; n = n / 2;
    }
    return 0;
}
void solve() {
    double x; int n; cin >> x >> n;
    double ans = myPow(x , n); cout << ans << endl;
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
