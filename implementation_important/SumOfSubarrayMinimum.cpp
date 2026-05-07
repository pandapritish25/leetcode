#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const long long mod = 1000000007LL;

vector<int> previous_smaller_element_index(vector<int> nums) {
    int n = nums.size();
    vector<int> psei(n , 0); stack <int> st;

    for (int i = 0; i < n; i++) {
        if (!st.empty() && nums[i] < nums[st.top()]) {
            while (!st.empty() && nums[i] < nums[st.top()]) st.pop();
        }
        if (st.empty()) {
            psei[i] = -1;
            st.push(i); 
        }
        else {
            if (!st.empty() && nums[i] >= nums[st.top()]) {
                psei[i] = st.top();
                st.push(i);
            }
        }
    }

    return psei;

}

vector<int> next_smaller_element_index(vector<int> nums) {
    int n = nums.size();
    vector<int> nse(n, 0); stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        if (!st.empty() && nums[i] <= nums[st.top()]) {
            while (!st.empty() && nums[i] <= nums[st.top()]) st.pop();
        }
        if (st.empty()) {
            nse[i] = n;
            st.push(i);
        }
        else {
            if (!st.empty() && nums[i] > nums[st.top()]) {
                nse[i] = st.top();
                st.push(i);
            }
        }
    }
    return nse;
}

long long mod_mul(int a , int b) {
    return ( (__int128)a * b ) % mod;
}

long long mod_add(int a , int b) {
    a %= mod;b %= mod;
    long long sum = (a + b) % mod;
    return sum % mod;
}


int sumSubarrayMins(vector<int>& arr) {
    vector<int> psei = previous_smaller_element_index(arr);
    vector<int> nse = next_smaller_element_index(arr);

    vector<int> index; int total_contri = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) index.push_back(i);

    for (int i = 0; i < n; ++i) {
        long long ans1 = index[i]; int ans2 = psei[i]; int ans3 = nse[i];
        long long left_diff = ans1 - ans2;
        long long right_diff = ans3 - ans1;
    
        long long contri = mod_mul(left_diff , right_diff);
        contri %= mod;
        long long contri_curr = mod_mul(contri , arr[i]);
        contri_curr %= mod;
        total_contri = mod_add(total_contri , contri_curr);
        total_contri %= mod;
    }
    return (int)total_contri % mod;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int ans = sumSubarrayMins(v);
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
