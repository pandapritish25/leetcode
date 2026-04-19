//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int maxProfit(vector<int>& prices) {
    if (prices.size() == 1) return 0;

    vector<int> suffix_max; int ans1 = INT_MIN;
    for (int i = prices.size() - 1; i >= 0; i--) {
        ans1 = max(ans1 , prices[i]); suffix_max.push_back(ans1); 
    }
    reverse(suffix_max.begin() , suffix_max.end());
    ans1 = INT_MIN;
    for (int i = 0; i < prices.size() - 1; i++) {
        ans1 = max(ans1 , suffix_max[i + 1] - prices[i]);
        ans1 = max(ans1 , 0LL);
    }
    
    return ans1;

}
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
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
