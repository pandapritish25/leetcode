//https://leetcode.com/problems/longest-consecutive-sequence/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int longestConsecutive(vector<int>& nums) {
    int max1 = 0;
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return 1;
    int count = 0;
    set<int> s;
    for (auto x : nums) s.insert(x);
    nums.clear(); for (auto x : s) nums.push_back(x);

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i + 1] - nums[i] == 1) {
            count ++;
        }
        else {
            max1 = max(max1 , count) ;
            count = 0;
        }
    }
    max1 = max(max1 , count);
    return max1 + 1;
}


void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << longestConsecutive(v) << endl;
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
