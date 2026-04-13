#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";

// just simple use of hashmaps
int majorityElement(vector<int>& nums) {
    map<int,int> mp; int max1 = 0;
    for (auto x : nums) mp[x] ++;
    for (auto i : mp) max1 = max(max1 , i.second);
    
    int ans = 0;
    for (auto i : mp) {
        if (i.second == max1) {
            ans = i.first;
        }
    }
    return ans;
}
void solve() {
   int n; cin >> n;
   vector<int> v(n);
   for (int i = 0; i < n ; i++) cin >> v[i];
   cout << majorityElement(v); 
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
