//https://leetcode.com/problems/set-matrix-zeroes/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

void setZeroes(vector<vector<int>>& matrix) {
    vector<pair<int,int>> helper;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) helper.push_back({i , j});
        }
    }
    if (helper.size() != 0) {
        for (int i = 0; i < helper.size(); i++) {
            int ans1 = helper[i].first; int ans2 = helper[i].second;

            for (int j = 0; j < matrix[0].size(); j++) matrix[ans1][j] = 0;
            for (int j = 0; j < matrix.size(); j++) matrix[j][ans2] = 0;
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void solve() {
    int m , n; cin >> m >> n;
    vector<vector<int>> v;
    for (int i = 0; i < m; i++) {
        vector<int> ans(n);
        for (int j = 0; j < n; j++)  cin >> ans[j];
        v.push_back(ans);
    }
    setZeroes(v);
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
