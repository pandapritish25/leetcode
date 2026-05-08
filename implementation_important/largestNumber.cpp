#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

bool cmp(string x , string y) {
    return x + y > y + x;
}
string largestNumber(vector<int>& nums) {
    int count_0 = 0; for (auto x : nums) if (x == 0) count_0 ++;
    if (count_0 == nums.size()) return "0";

    vector<string> v; for (auto x : nums) v.push_back(to_string(x));

    sort(v.begin() , v.end() , cmp);

    string ans; for (auto x : v) ans += x;

    return ans;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << largestNumber(v) << endl;
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
