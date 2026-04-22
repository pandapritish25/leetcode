//https://leetcode.com/problems/jump-game/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

bool canJump(vector<int>& nums) {
    set <int> s; bool ok = true;

    for (int i = 0; i < nums.size(); i++) {
        if (!s.empty()) {
            if (*s.rbegin() < i) {
                ok = false; break;
            }
        }
        s.insert(nums[i] + i);
    }
    return ok;        
}

void solve() {
    int n , k; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << canJump(v) << endl;
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
