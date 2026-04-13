//https://leetcode.com/problems/palindrome-number/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";

bool isPalindrome(int x) {
    if (x < 0) return 0;
    string ans1 = to_string(x);
    string ans2 = ans1;
    reverse(ans2.begin() , ans2.end());
    return ans1 == ans2;
}
void solve() {
    int n; cin >> n;
    bool ans = isPalindrome(n);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
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
