#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> previous_smaller_element(vector<int> height) {
    int n = height.size();
    vector<int> pse(n , 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[st.top()] >= height[i]) st.pop();
        
        if (st.empty()) {
            pse[i] = -1;
            st.push(i);
            continue;
        }

        if (!st.empty() && height[st.top()] < height[i]) {
            pse[i] = st.top();
            st.push(i);
            continue;
        }
    }
    return pse;
}
vector<int> next_smaller_element(vector<int> height) {
    int n = height.size();
    vector<int> nse(n , 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && height[st.top()] >= height[i]) st.pop();
        
        if (st.empty()) {
            nse[i] = n;
            st.push(i);
            continue;
        }

        if (!st.empty() && height[st.top()] < height[i]) {
            nse[i] = st.top();
            st.push(i);
            continue;
        }
    }
    return nse;

}
int largestRectangleArea(vector<int>& heights) {
    vector<int> left = previous_smaller_element(heights);
    vector<int> right = next_smaller_element(heights);
    int n = heights.size(); int max1 = 0;

    for (int i = 0; i < n; i++) {
        int height = heights[i];
        int width = right[i] - left[i] - 1;
        int area = width * height;
        max1 = max(max1 , area);
    }
    return max1;
}
void solve() {
    int n; cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) cin >> height[i];
    cout << largestRectangleArea(height) ;
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
