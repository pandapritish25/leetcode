//https://leetcode.com/problems/rotate-image/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin() , matrix.end());
    for (int i = 0; i < matrix.size(); i++) 
        for (int j = i + 1; j < matrix.size(); j++) swap(matrix[i][j] , matrix[j][i]);
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++) {
        vector<int> ans(n);
        for (int j = 0; j < n; j++) cin >> ans[j];
        matrix.push_back(ans);
    }
    rotate(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << matrix[i][j] << " ";
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
