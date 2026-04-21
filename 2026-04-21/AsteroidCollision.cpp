//https://leetcode.com/problems/asteroid-collision/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long


vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st; vector<int> ans;
    if (asteroids.size() == 1) return asteroids;

    for (int i = 0; i < asteroids.size(); i++) {
        if (asteroids[i] > 0) {
            st.push(asteroids[i]); continue;
        }
        if (asteroids[i] < 0 && st.empty()) {
            st.push(asteroids[i]); continue;
        }
        if (asteroids[i] < 0 && st.top() < 0) {
            st.push(asteroids[i]); continue;
        }
        if (asteroids[i] < 0 && !st.empty()) {
            int ok = 0;
            int x = abs(asteroids[i]); 
            // cout << st.top() << endl;
            while (!st.empty()) {
                if (st.top() < 0) {
                    st.push(-x);
                    break;
                }
                else if (st.top() > x) {
                    break;
                }
                else if (!st.empty() && st.top() > 0 && x > st.top()) {
                    st.pop();
                }
                else if (st.top() == x) {
                    ok = 1;
                    st.pop();
                    break;
                }
            }
            if (st.empty() && ok == 0) st.push(asteroids[i]);
        }
    }

    if (st.empty()) return ans;

    while (!st.empty()){
        ans.push_back(st.top()); 
        st.pop();
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> ans = asteroidCollision(v);
    for (auto x:ans) cout << x << " ";
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
