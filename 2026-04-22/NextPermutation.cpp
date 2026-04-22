//https://leetcode.com/problems/next-permutation/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

void nextPermutation(vector<int>& nums) {
    vector<int> x = nums; sort(x.begin() , x.end()); reverse(x.begin() , x.end());
    vector<int> ans(nums.size());
    int index = 0;
    if (x == nums) {
        sort(x.begin() , x.end()); nums = x; ans = x;
    }
    else {
        vector<int> suffix_max; int max1 = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            max1 = max(max1 , nums[i]); suffix_max.push_back(max1);
        }
        reverse(suffix_max.begin() , suffix_max.end());
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == suffix_max[i]) continue;
            else {
                index = i; break;
            }
        }

        int index_exch = 0; int min1 = INT_MAX;
        for (int i = index + 1; i < nums.size(); i++) {
            if (nums[i] < min1 && nums[i] > nums[index]) {
                min1 = nums[i];
                index_exch = i;
            }
        }
        int count = 0;
        ans = nums;
        swap(ans[index] , ans[index_exch]);
        sort(ans.begin() + index + 1 , ans.end());

        nums = ans;
    }
    for (auto x : nums) cout << x << " ";
}
void solve() {
    int n , k; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    nextPermutation(v);
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
