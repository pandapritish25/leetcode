//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int maxProfit(vector<int>& prices) {
    if (prices.size() == 1) return 0;

    vector<int> suffix_max; int max1 = 0;
    for (int i = prices.size() - 1; i >= 0; i--) {
        max1 = max(max1 , prices[i]); suffix_max.push_back(max1);
    }
    reverse(suffix_max.begin() , suffix_max.end()); int ans = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
        ans = max(ans , (suffix_max[i + 1] - prices[i]));
        ans = max(ans , 0LL);
    }
    return ans;
}
void solve() {
    int n; cin >> n; vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans = maxProfit(v); cout << ans << endl;
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
