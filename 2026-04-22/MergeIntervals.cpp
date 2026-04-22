//https://leetcode.com/problems/merge-intervals/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    multiset <pair <int,int>> x; vector<vector<int>> ans;
    if (intervals.empty()) return ans;

    for (auto y : intervals) x.insert({y[0] , y[1]});

    while (!x.empty()) {
        if (x.size() == 1) {
            auto it = x.begin();
            ans.push_back({it->first , it->second});
            break;
        }
        auto it1 = x.begin(); auto it2 = next(x.begin() , 1);
        if (it1->second >= it2-> first) {
            x.insert({it1->first , max(it1->second , it2->second)});
            x.erase(it1); x.erase(it2);
        }
        else {
            ans.push_back({it1->first , it1->second}); x.erase(it1);
        }
    }

    return ans; 
}
void solve() {
    int n; cin >> n;
    vector<vector<int>> intervals;

    for (int i = 0; i < n; i++) {
        vector<int> x(2);
        for (int j = 0; j < 2; j++) cin >> x[j];
        intervals.push_back(x);
    }

    vector<vector<int>> ans = merge(intervals);
    for (auto x : ans) {
        for (auto i : x) cout << i << " ";
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
