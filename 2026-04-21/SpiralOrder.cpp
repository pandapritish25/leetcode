//https://leetcode.com/problems/spiral-matrix/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size(); int m = matrix[0].size();

    vector<int> ans;

    int row_begin = 0; int col_begin = 0; int row_end = n - 1; int col_end = m - 1;
    while (row_begin <= row_end && col_begin <= col_end) {
        if (row_begin <= row_end) {
            for (int j = col_begin; j <= col_end; j++) ans.push_back(matrix[row_begin][j]);
            row_begin ++;
        }
        if (col_begin <= col_end) {
            for (int j = row_begin; j <= row_end; j++) ans.push_back(matrix[j][col_end]);
            col_end --;
        }
        if (row_begin <= row_end) {
            for (int j = col_end; j >= col_begin; j--) ans.push_back(matrix[row_end][j]);
            row_end --;
        }
        if (col_begin <= col_end) {
            for (int j = row_end; j >= row_begin; j--) ans.push_back(matrix[j][col_begin]);
            col_begin ++;
        }
    }
    return ans;
}
void solve() {
    int n , m; cin >> n >> m;
    vector<vector<int>> helper;
    for (int i = 0; i < n; i++) {
        vector<int> x(m);
        for (int j = 0; j < m; j++) {
            cin >> x[j];
        }
        helper.push_back(x);
    }
    vector<int> ans = spiralOrder(helper);
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
