//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long
// 2 approaches , you need to use any one approach

// 1st approach
int removeDuplicates(vector<int>& nums) {
    int count = 0; int prev_end = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != prev_end) {
            nums[count] = nums[i]; count ++; prev_end = nums[i];
        }
    }

    return count;
}
// 2nd approach
int removeDuplicates(vector<int>& nums) {
    vector<int> ans;
    int prev_end = INT_MIN; int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (prev_end == nums[i]) {
            continue;
        }
        else {
            prev_end = nums[i];
            ans.push_back(nums[i]);
        }
    }
    nums = ans;
    // for (auto x : nums) cout << x << " ";
    int ans1 = nums.size(); return ans1;
}

void solve() {
    int n; cin >> n; vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int ans = removeDuplicates(v);
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
