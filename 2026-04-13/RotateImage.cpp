//https://leetcode.com/problems/rotate-image/description/?envType=problem-list-v2&envId=math
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";

// simply reverse the array and then change the symmetry
// for changing the symmetry , you can do for (i -- n) for (j = i + 1 -- n) swap
// because we would be having matrix[i][j] and matrix[j][i] so we would be needing to swap them
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // reversing the matrix and swapping them
    reverse(matrix.begin() , matrix.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j] , matrix[j][i]);
        }
    }
}
void solve() {
    int n; cin >> n;
    vector<vector<int>> helper;

    for (int i = 0; i < n; i++) {
        vector<int> x(n);
        for (int j = 0; j < n; j++) cin >> x[j];
        helper.push_back(x);
    }

    rotate(helper);
    for (auto i : helper) {
        for (auto x : i) cout << x << " ";
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
