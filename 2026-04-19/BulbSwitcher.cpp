//https://leetcode.com/problems/bulb-switcher/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

// what happens is evert no becomes on and off only for their factors so for every number that has odd factors
// we have the anwser that for everybulb that has odd no of factors , and odd no of factors have only perfect square nos

int bulbSwitch(int n) {
    int ans = sqrt(n); return ans;
}

void solve() {
    int l; cin >> l;
    int ans = bulbSwitch(l); cout << ans << endl;
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
