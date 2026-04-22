//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

bool comparator(vector<int> &v1 , vector<int> &v2) {
    return v1[1] < v2[1];
}
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin() , points.end() , comparator); int arrow_shot = 1;

    int mini = points[0][1]; 

    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] <= mini) continue;
        mini = points[i][1]; arrow_shot ++;
    }
    
    return arrow_shot;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> points;

    for (int i = 0; i < n; i++) {
        vector<int> x(2);
        for (int j = 0; j < 2; j++) cin >> x[j];
        points.push_back(x);
    }
    int ans = findMinArrowShots(points);
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
