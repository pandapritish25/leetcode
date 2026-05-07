#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> previous_smaller_element_equal(vector<int> nums) {
    int n = nums.size();
    vector<int> psee(n , 0); stack<int> st;


    for (int i = 0; i < n; i++) {
        if (!st.empty() && nums[i] < nums[st.top()]) {
            while (!st.empty() && nums[i] < nums[st.top()]) st.pop();
        }

        if (st.empty()) {
            psee[i] = -1;
            st.push(i);
        }
        else {
            if (!st.empty() && nums[i] >= nums[st.top()]) {
                psee[i] = st.top();
                st.push(i);
            }
        }
    }

    return psee;
}
vector<int> previous_greater_element_equal(vector<int> nums) {
    int n = nums.size();
    vector<int> pgee(n , 0); stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] > nums[st.top()]) st.pop();

        if (st.empty()) {
            pgee[i] = -1;
            st.push(i);
        }

        else {
            if (!st.empty() && nums[i] <= nums[st.top()]) {
                pgee[i] = st.top();
                st.push(i);
            }
        }
    }
    return pgee;
}
vector<int> next_smaller_element(vector<int> nums) {
    int n = nums.size();
    vector<int> nse(n , 0); stack<int> st;

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
vector<int> next_greater_element(vector<int> nums) {
    int n = nums.size();
    vector<int> nge(n , 0); stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[i] >= nums[st.top()]) st.pop();

        if (st.empty()) {
            nge[i] = n;
            st.push(i);
        }

        else {
            if (!st.empty() && nums[i] < nums[st.top()]) {
                nge[i] = st.top();
                st.push(i);
            }
        }
    }
    return nge;
}

long long calc_subarraysum_minimum(vector<int> nums) {
    int n = nums.size();

    vector<int> take1 = previous_smaller_element_equal(nums);
    vector<int> take2 = next_smaller_element(nums);


    long long sum1 = 0;
    for (int i = 0; i < n; i++) {
        long long ans1 = i - take1[i];
        long long ans2 = take2[i] - i;
        long long prod = (ans1 * ans2);
        long long contri = prod * nums[i];
        sum1 += (long long) contri;
    }

    return (long long) sum1;
}
long long calc_subarraysum_maximum(vector<int> nums) {
    int n = nums.size();

    vector<int> take1 = previous_greater_element_equal(nums);
    vector<int> take2 = next_greater_element(nums);

    long long sum1 = 0;
    for (int i = 0; i < n; i++) {
        long long ans1 = i - take1[i];
        long long ans2 = take2[i] - i;
        long long prod = (ans1 * ans2);
        long long contri = prod * nums[i];
        sum1 += (long long) contri;
    }

    return (long long) sum1;
}
long long subArrayRanges(vector<int>& nums) {
    long long ans1 = calc_subarraysum_minimum(nums);
    long long ans2 = calc_subarraysum_maximum(nums);


    long long sum_ans = ans2 - ans1;
    return sum_ans * 1LL;
}

void solve() {
    int n; cin >> n; vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    long long ans = subArrayRanges(v);
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
    