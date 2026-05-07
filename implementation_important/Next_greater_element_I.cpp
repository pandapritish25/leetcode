#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int x = nums1.size();int n = nums2.size();
    stack<int> st; 
    vector<int> nge(n , 0);

    for (int i = n - 1; i >= 0; i--) {
        if (!st.empty() && nums2[i] >= st.top()) {
            while (!st.empty() && nums2[i] >= st.top()) st.pop();
        }

        if (st.empty()) {
            nge[i] = -1;
            st.push(nums2[i]);
            continue;
        }

        if (!st.empty() && nums2[i] < st.top()) {
            nge[i] = st.top();
            st.push(nums2[i]);
            continue;
        }
    }

    map <int,int> mp;
    for (int i = 0; i < nums2.size(); i++) mp[nums2[i]] = nge[i];

    vector<int> ans;

    for (int i = 0; i < x; i++) {
        ans.push_back(mp[nums1[i]]);
    }
    return ans;
    
}

void solve() {
    int n1 , n2; cin >> n1 >> n2;
    vector<int> x1(n1) , x2(n2);

    for (int i = 0; i < n1; i++) cin >> x1[i];
    for (int i = 0; i < n2; i++) cin >> x2[i];

    vector<int> ans = nextGreaterElement(x1 , x2);

    for (auto x : ans) cout << x << " ";
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
