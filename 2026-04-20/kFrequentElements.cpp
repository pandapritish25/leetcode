#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> topKFrequent(vector<int>& nums, int k) {
    map <int,int> mp;
    for (int i = 0; i < nums.size(); i++) mp[nums[i]] ++;
    vector<int> ans;

    set <pair<int,int>> s; for (auto i : mp) s.insert ({i.second , i.first});
    for (int i = 0; i < k; i++) {
        pair<int,int> y = *s.rbegin();
        ans.push_back(y.second);
        s.erase(y);
    }
    return ans;
}

void solve() {
    int n; cin >> n; int k; cin >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> ans = topKFrequent(v , k);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
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
