//https://leetcode.com/problems/ugly-number/submissions/1982490333/
#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isUgly(int n) {
    if (n == 0) return false;

    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;
    
    return n == 1;
}
void solve() {
    int n; cin >> n;
    cout << isUgly(n) << endl;

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
