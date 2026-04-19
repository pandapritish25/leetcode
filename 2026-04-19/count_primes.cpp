//https://leetcode.com/problems/count-primes/
#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> sieve(int n) {
    vector<int> ans;
    int arr[n + 1];
    for (int i = 0; i < n; i++) arr[i] = 1;

    for (int i = 2; i < n; i++) {
        if (arr[i] == 1) {
            for (int j = 2 * i; j < n; j += i) arr[j] = 0;
        }
    } 
    int count = 0;
    for (int i = 2; i < n; i++) if (arr[i] == 1) ans.push_back(i);
    return ans;
}
int countPrimes(int n) {
    if (n < 2) return 0;
    vector<int> ans = sieve(n);
    if (ans.size() == 0) return 0;
    int x = ans.size(); return x;
}
void solve() {
    int n; cin >> n;
    cout << countPrimes(n) << endl;
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
