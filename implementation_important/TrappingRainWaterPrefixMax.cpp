#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int trap(vector<int>& height) {
    int sum = 0; int n = height.size();

    vector<int> prefix_max , suffix_max; 
    int max1 = INT_MIN;

    for (int i = 0; i < n; i++) {
        max1 = max(max1 , height[i]);
        prefix_max.push_back(max1);
    }
    max1 = INT_MIN;
    reverse(height.begin() , height.end());

    for (int i = 0; i < n; i++) {
        max1 = max(max1 , height[i]);
        suffix_max.push_back(max1);
    }

    reverse(height.begin() , height.end());
    reverse(suffix_max.begin() , suffix_max.end());

    for (int i = 0; i < n; i++) {
        if (height[i] < prefix_max[i] && height[i] < suffix_max[i]) {
            int x1 = min(prefix_max[i] , suffix_max[i]) - height[i];
            x1 = max(x1 , 0LL);
            sum += x1;
        }
    }
    return sum;

}
void solve() {
    int n; cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) cin >> height[i];
    cout << trap(height) << endl;
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
