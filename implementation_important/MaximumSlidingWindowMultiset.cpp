#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
   
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans; multiset<int> s;

    for (int i = 0; i < k; i++) s.insert(nums[i]);
    ans.push_back(*s.rbegin());

    for (int i = k; i < nums.size(); i++) {
        s.erase(s.find(nums[i - k]));
        s.insert(nums[i]);
        ans.push_back(*s.rbegin());
    }
    return ans;
}
void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> ans = maxSlidingWindow(v , k);
    for (auto x : ans) cout << x << " ";
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
