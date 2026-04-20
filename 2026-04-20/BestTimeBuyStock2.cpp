//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/ 2 approaches for this question one is single buy on and the second is multi buy on
#include<bits/stdc++.h>
using namespace std;
#define int long long

// this is only valid when you you will take 1 stock and then sell and on that day you dont but any stock
int maxProfit(vector<int>& prices) {
    vector<int> suffix_max; int max1 = 0;
    for (int i = prices.size() - 1; i >= 0; i--) {
        max1 = max(max1 , prices[i]); suffix_max.push_back(max1);
    }
    reverse(suffix_max.begin() , suffix_max.end()); int ans = 0; int prev_end = INT_MAX;
    int ok = 0;

    for (int i = 0; i < prices.size() - 1; i++) {
        int curr = prices[i]; 
        if (curr > suffix_max[i + 1] && ok == 0) continue; 

        cout << prev_end << " " << prices[i] << endl;
        if (prev_end <= prices[i]) {
            // cout << i << " ";
            // cout << prev_end << ' ' << prices[i] << endl;
            ans += (prices[i] - prev_end);
            prev_end = INT_MAX;
            continue;
            ok = 0;
        }
        prev_end = prices[i];
        ok = 1;
    }
    // ans = max(ans , 0LL); ans = min(ans , 0LL);
    return ans; 
}
int maxProfit1(vector<int> &prices) {
    int ans = 0;
    for (int i = 1; i < prices.size(); i++) ans = ans + max(prices[i] - prices[i - 1] , 0LL);
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
