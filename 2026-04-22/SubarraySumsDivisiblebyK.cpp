//https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod(int n , int k) {
    int ans = ((n % k) + k) % k;
    return ans;
}
int subarraysDivByK(vector<int>& nums, int k) {
    vector<int> prefix_sum; int count = 0; int sum = 0; map <int,int> mp;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i]; prefix_sum.push_back(sum);
    }

    for (int i = 0; i < nums.size(); i++) {
        int ans1 = mod(prefix_sum[i] , k); prefix_sum[i] = ans1;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (prefix_sum[i] == 0) count ++;
        if (mp.find(prefix_sum[i]) != mp.end()) count += mp[prefix_sum[i]];
        mp[prefix_sum[i]] ++;
    }
    return count;
}
void solve() {
    int n , k; cin >> n >> k;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << subarraysDivByK(v , k) << endl;
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
