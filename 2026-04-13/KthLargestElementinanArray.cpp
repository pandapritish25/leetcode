//https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=problem-list-v2&envId=array
// KthLargestElementinanArray.cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";

// using priority queue without any sortings , a simple usage of priority_queue
int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) pq.push(nums[i]);

    int count = 1;

    while (!pq.empty()) {
        if (count == k) {
            return pq.top();
        }
        pq.pop(); count ++;
    }
    return 0;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int k; cin >> k;
    int ans = findKthLargest(v , k);
    cout << ans << endl;

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
