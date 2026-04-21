//https://leetcode.com/problems/contains-duplicate-ii/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long


bool containsNearbyDuplicate(vector<int>& nums, int k) {
    vector<pair<int,int>> helper;
    for (int i = 0; i < nums.size(); i++) helper.emplace_back(nums[i] , i);
    sort(helper.begin() , helper.end()); bool ok = false;
    
    for (int i = 0; i < helper.size() - 1; i++) {
        if (helper[i].first == helper[i + 1].first && abs(helper[i].second - helper[i + 1].second) <= k) {
            ok = true; break;
        }
    }
    return ok;
}
void solve() {
    int n; cin >> n; vector<int>v(n);int k; cin >> k;
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << containsNearbyDuplicate(v , k);
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
