#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> previous_greater_element(vector<int> nums) {
    int n = nums.size();
    stack<int> st; vector<int> pge(n , 0);

    for (int i = 0; i < n; i++) {
        if (!st.empty() && nums[st.top()] <= nums[i]) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        }
        if (st.empty()) {
            st.push(i);
            pge[i] = -1;
            continue;
        }
        if (!st.empty() && nums[st.top()] > nums[i]) {
            pge[i] = st.top(); st.push(i);
            continue;
        }
    }
    vector<int> stock_span(n , 0);
    for (int i = 0; i < n; i++) {
        if (pge[i] == -1) stock_span[i] = 1;
        else stock_span[i] = i - pge[i];
    }
    return pge;
}   
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> ans = previous_greater_element(v);
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
