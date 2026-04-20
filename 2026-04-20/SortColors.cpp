#include<bits/stdc++.h>
using namespace std;
#define int long long

void sortColors(vector<int>& nums) {
    int count0 = 0 , count1 = 0 , count2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) count0 ++;
        if (nums[i] == 1) count1 ++;
        if (nums[i] == 2) count2 ++;
    }
    int count = 0;
    if (count0 > 0) {
        for (int i = 0; i < count0; i++) {
            nums[count] = 0; count ++;
        }
    }

    if (count1 > 0) {
        for (int i = 0; i < count1; i++) {
            nums[count] = 1; count ++;
        }
    }

    if (count2 > 0) {
        for (int i = 0; i < count2; i++) {
            nums[count] = 2; count ++;
        }
    }
}
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sortColors(v); for (auto x : v) cout << x << " ";
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
