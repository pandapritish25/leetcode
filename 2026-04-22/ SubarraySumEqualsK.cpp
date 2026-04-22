//https://leetcode.com/problems/subarray-sum-equals-k/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int subarraySum(vector<int>& nums, int k) {
    map <int,int> mp; int count = 0; vector<int> prefix_sum; int sum = 0;

    for (int i = 0; i < nums.size(); i++) sum += nums[i] , prefix_sum.push_back(sum);
    // for (auto x:prefix_sum) cout << x << " ";

    for (int i = 0; i < nums.size(); i++) {
        if (prefix_sum[i] == k)  count ++;
        if (mp.find(prefix_sum[i] - k) != mp.end()) count += mp[prefix_sum[i] - k];
        mp[prefix_sum[i]] ++;
    }
    return count;
}

void solve() {
    int n , k; cin >> n >> k;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << subarraySum(v , k) << endl;
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
