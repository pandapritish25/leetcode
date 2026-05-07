#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.push(asteroids[i]); continue;
        }

        if (!st.empty() && st.top() * asteroids[i] > 0) {
            st.push(asteroids[i]);
            continue;
        }

        if (!st.empty() && st.top() < 0 && asteroids[i] > 0) {
            st.push(asteroids[i]);
            continue;
        }

        if (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                if (!st.empty() && abs(asteroids[i]) > st.top()) {
                    st.pop();
                }
                if (!st.empty() && abs(asteroids[i]) == st.top()) {
                    st.pop();
                    break;
                }
                if (!st.empty() && st.top() < 0) {
                    st.push(asteroids[i]); break;
                }
                if (st.empty()) {
                    st.push(asteroids[i]); break;
                }
                if (!st.empty() && abs(asteroids[i]) < st.top()) {
                    break;
                }
            }
        }
    }

    vector<int> ans;
    while (!st.empty()) {
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
