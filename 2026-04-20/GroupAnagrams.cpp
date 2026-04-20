//https://leetcode.com/problems/group-anagrams/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string , vector<string>> mp;
    for (int i = 0; i < strs.size(); i++) {
        string y = strs[i];
        sort(y.begin() , y.end());
        mp[y].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto x : mp) ans.push_back(x.second);
    return ans;
}


void solve() {
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<string>> x = groupAnagrams(v);
    for (auto y : x) {
        for (auto i : y) cout << i << " ";
        cout << endl;
    } 
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
