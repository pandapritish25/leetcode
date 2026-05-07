#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> previousSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nse(n , 0); stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!st.empty() && nums[i] <= st.top()) {
            while (!st.empty() && nums[i] <= st.top()) st.pop();
        }

        if (st.empty()) {
            nse[i] = -1;
            st.push(nums[i]);
            continue;
        }

        if (!st.empty() && nums[i] > st.top()) {
            nse[i] = st.top();
            st.push(nums[i]);
            continue;
        }
    }
    return nse;
}

void solve() {
    int n1 , n2; cin >> n1;
    vector<int> x1(n1);

    for (int i = 0; i < n1; i++) cin >> x1[i];

    vector<int> ans = previousSmallerElement(x1);

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
