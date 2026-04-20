//https://leetcode.com/problems/remove-element/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int removeElement(vector<int>& nums, int val) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] != val) nums[count] = nums[i] , count ++;
    }
    return count;
}

void solve() {
    int n; cin >> n; vector<int> v(n); int val; cin >> val;
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans = removeElement(v , val); cout << ans << endl;

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
