#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();

    vector<int> nge(n , 0);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {
        if (!st.empty() && nums[i % n] >= st.top()) {
            while (!st.empty() && nums[i % n] >= st.top()) st.pop();
        }
        if (st.empty()) {
            if (i < n) nge[i] = -1;
            st.push(nums[i % n]);
        }
        else if (!st.empty() && nums[i % n] < st.top()) {
            if (i < n) nge[i] = st.top();
            st.push(nums[i % n]);
        }
    }
    return nge;
}

void solve() {
    int n1 , n2; cin >> n1;
    vector<int> x1(n1);

    for (int i = 0; i < n1; i++) cin >> x1[i];

    vector<int> ans = nextGreaterElements(x1);

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
