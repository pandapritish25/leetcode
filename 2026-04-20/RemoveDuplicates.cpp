// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int removeDuplicates(vector<int>& nums) {
    int prev_end = INT_MIN; int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == prev_end) continue;
        prev_end = nums[i];
        nums[count] = nums[i]; count ++;
    }
    for (auto x : nums) cout << x << " ";
    return count ;
}
void solve() {
    int n; cin >> n; vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans = removeDuplicates(v); cout << ans << endl;
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
