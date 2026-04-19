//https://leetcode.com/problems/check-if-it-is-a-straight-line/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

bool checkStraightLine(vector<vector<int>>& coordinates) {
    set<double> ans;
    int n = coordinates.size(); 
    set<int> ans1 , ans2;

    for (int i = 0; i < n; i++) ans1.insert(coordinates[i][0]);
    for (int i = 0; i < n; i++) ans2.insert(coordinates[i][1]);
    
    if (ans1.size() == 1) return true;
    if (ans2.size() == 1) return true;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double x1 = coordinates[i][0];
            double y1 = coordinates[i][1];
            double x2 = coordinates[j][0];
            double y2 = coordinates[j][1]; 
            double slope = ((y2 - y1) / (x2 - x1)) * 1.0;
            ans.insert(slope);
        }
    }
    return ans.size() == 1;
}
void solve() {
    int n; cin >> n; vector<vector<int>> v;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int x , y; cin >> x >> y; 
        ans.push_back(x);ans.push_back(y);v.push_back(ans);ans.clear();
    }
    bool x1 = checkStraightLine(v);

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
