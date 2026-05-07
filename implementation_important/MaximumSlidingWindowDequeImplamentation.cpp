#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size(); vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();

        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back(); 
        dq.push_back(i);

        if (i >= k - 1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}
void solve() {
    int n; cin >> n; int k; cin >> k;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];

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
