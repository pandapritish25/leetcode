// https://leetcode.com/problems/two-sum/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    map <int,int> pos_store;

    // storing the position for each of the indices
    for (int i = 0; i < nums.size(); i++) {
        pos_store[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
        int curr = nums[i]; int req = target - nums[i];
        int curr_index = i;
        // reason is if you query inside a map , this would be giving you an error so query inside only

        if (pos_store.count(req)) {
            int req_index = pos_store[req];
            if (curr_index != req_index) {
                ans.push_back(curr_index); ans.push_back(req_index);
                break;
            }
        }
    }
    sort(ans.begin() , ans.end());
    return ans;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int s; cin >> s;
    vector<int> ans = twoSum(v , s);
    for (auto x : ans) cout << x << " ";
    cout << endl; 
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
