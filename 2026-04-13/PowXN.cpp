//https://leetcode.com/problems/powx-n/?envType=problem-list-v2&envId=math
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";

double myPow(double x, int n) {
    // handling the edge cases for 0 and 1
    if (n == 0) return 1.0;
    if (x == 0) return 0.0;
    if (x == 1) return 1.0;
    
    if (n == 1) return x;
    if (n < 0)  x = (1 / x) * 1.0;
    

    // handling the edge case for -1 
    if (x == -1) {
        if (n % 2 == 1) {
            return -1.0;
        }
        else return 1.0;
    }
    // and then we would be hanflinf INT_MIN and INT_MAX case
    if (n <= INT_MIN || n >= INT_MAX) return 0;
    n = abs(n);
    double ans = 1.0;
    while (n) {
        if (n % 2 == 1) {
            ans = ans * x * 1.0;
        }
        n = n / 2;
        x = x * x * 1.0;
    }
    return ans;
}

void solve() {
    double n ; int x; cin >> n >> x;
    cout << myPow(n , x);
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
