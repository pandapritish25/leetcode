//https://leetcode.com/problems/maximum-subarray/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

// 2 approach one is neg numbers inside and second is neg numbers  outside
int maxSubArray1(vector<int>& nums) {
    int count = 0; int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) count ++;
        maxi = max(nums[i] , maxi);
    }
    if (count == nums.size()) return maxi;
    int curr_max = 0; int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum < 0) sum = 0;
        curr_max = max(curr_max, sum);
    }
    return curr_max;
}
// neg numbers inside

int maxSubArray(vector<int>& nums) {
    int curr_max = 0; int sum = 0; int count = 0; int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (nums[i] < 0) count ++ , maxi = max(maxi , nums[i]);
        if (sum < 0) sum = 0;
        curr_max = max(curr_max , sum);
    }
    if (count == nums.size()) return maxi;
    return curr_max;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << maxSubArray(v) << endl;
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
