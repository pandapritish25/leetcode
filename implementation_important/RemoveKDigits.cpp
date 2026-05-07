#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

string removeKdigits(string nums, int k) {
    string ans; int n = nums.size();
    stack <int> st;

    for (int i = 0; i < n; i++) {
        int ans1 = nums[i] - '0';
        if (k == 0) {
            st.push(ans1); continue;
        }
        if (st.empty()) {
            st.push(ans1); continue;
        }

        if (!st.empty() && st.top() <= ans1) {
            st.push(ans1); continue;
        }

        if (!st.empty() && st.top() > ans1 && k > 0) {
            while (!st.empty() && st.top() > ans1 && k > 0) {
                st.pop(); k --;
            }
            st.push(ans1);
        }
    }   

    while (!st.empty() && k > 0) {
        k --;
        st.pop();
    }
    while (!st.empty()) {
        char t1 = st.top() + '0';
        ans.push_back(t1);
        st.pop();
    }
    while (ans.size() > 0 && ans.back() == '0') ans.pop_back();
    if (ans.size() == 0) return "0";
    reverse(ans.begin() , ans.end());
    return ans;
}
void solve() {
    string s; int k; cin >> s >> k;
    string ans = removeKdigits(s , k);

    cout << ans << endl;
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
