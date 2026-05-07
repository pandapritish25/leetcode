#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefix_sum;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        sum %= k;
        prefix_sum.push_back(sum);
    }
    map<int,int> mp;
    bool ok = false;

    for (int i = 0; i < n; i++) {
        if (prefix_sum[i] == 0) {
            if (i >= 1) {
                ok = true; break;
            }
        }
        if (mp.find(prefix_sum[i]) != mp.end() && i - mp[prefix_sum[i]] >= 2) {
            ok = true; break;
        }
        else if (mp.find(prefix_sum[i]) == mp.end()) {
            mp[prefix_sum[i]] = i;
        }
    }
    return ok;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); int k; cin >> k;
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << checkSubarraySum(v , k);
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
