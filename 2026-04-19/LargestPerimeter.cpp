//https://leetcode.com/problems/largest-perimeter-triangle/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check(int a , int b , int c) {
    if ((a + b) > c && (b + c) > a && (a + c) > b) return true;
    return false;
}

int largestPerimeter(vector<int>& nums) {
    sort(nums.begin() , nums.end(), greater<int>());
    for (int i = 0; i <= nums.size() - 3; i++) {
        if (check(nums[i], nums[i + 1] , nums[i + 2])) {
            return nums[i] + nums[i + 1] + nums[i + 2];
        }
    }   
    return 0;
}
void solve() {
    int n; cin >> n; vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans = largestPerimeter(v); cout << ans << endl;
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
