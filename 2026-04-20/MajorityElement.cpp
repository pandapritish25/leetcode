//https://leetcode.com/problems/majority-element/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int majorityElement(vector<int>& nums) {
    int max1 = 0; int ans = 0;
    map<int,int> mp; for (int i = 0; i < nums.size(); i++) mp[nums[i]] ++;
    for (auto x : mp) max1 = max(max1 , x.second);
    for (auto x : mp) if (x.second == max1) ans = x.first;
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << majorityElement(v) << endl;
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
