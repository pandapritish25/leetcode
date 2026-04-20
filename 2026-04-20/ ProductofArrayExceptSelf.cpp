//https://leetcode.com/problems/product-of-array-except-self/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> productExceptSelf(vector<int>& nums) {
    int ok = 0; int prod = 1;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            count ++;
            ok = 1; continue;
        }
        prod = prod * nums[i];
    }
    vector<int> ans;
    if (ok != 1) {
        for (int i = 0; i < nums.size(); i++) ans.push_back(prod / nums[i]);
        return ans;
    }
    if (ok == 1 && count > 1) {
        for (int i = 0; i < nums.size(); i++) ans.push_back(0);
        return ans;
    }
    if (ok == 1 && count == 1) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) ans.push_back(0);
            else ans.push_back(prod);
        }
        return ans;
    }
    return ans;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> ans = productExceptSelf(v);
    for (int i = 0; i < n; i++) cout << ans[i] << " "; 
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
