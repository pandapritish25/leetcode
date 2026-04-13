//https://leetcode.com/problems/rotate-array/description/?envType=problem-list-v2&envId=math
// simply using k%n
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";

vector<int> rotate(vector<int>& nums, int k) {
    int ns1 = k % nums.size();
    if (ns1 == 0) return nums;
    vector<int> ans;
    for (int i = nums.size() - ns1; i < nums.size(); i++) ans.push_back(nums[i]);
    for (int i = 0; i < nums.size() - ns1; i++) ans.push_back(nums[i]);
    return ans;
}
void solve() {
   int n; cin >> n;
   vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
   int k; cin >> k;
   vector<int> ans = rotate(v , k);
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
