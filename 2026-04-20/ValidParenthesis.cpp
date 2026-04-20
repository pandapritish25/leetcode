//https://leetcode.com/problems/valid-parentheses/description/
//hashmap implementation
#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isValid(string s) {
    map<char , int> mp;
    mp['('] = -1;
    mp[')'] = 1;
    mp['{'] = -2;
    mp['}'] = 2;
    mp['['] = -3;
    mp[']'] = 3;

    stack<int> st; bool ok = true;
    for (int i = 0; i < s.length(); i++) {
        if (mp[s[i]] < 0) st.push(mp[s[i]]);

        if (mp[s[i]] > 0 && st.empty()) {
            ok = false; break;
        }
        if (mp[s[i]] > 0 && (mp[s[i]] + st.top()) != 0) {
            ok = false; break;
        }
        if (mp[s[i]] > 0 && (mp[s[i]] + st.top()) == 0) {
            if (!st.empty()) st.pop();
        }
    }
    if (ok == false) return false;
    if (st.size() != 0) return false;
    return true;
}
void solve() {
    string s; cin >> s;
    cout << isValid(s) << endl;
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
