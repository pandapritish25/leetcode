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
int maximalRectangle(vector<vector<char>>& matrix) {
    vector<vector<int>> matrix1;
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        vector<int> x;
        for (int j = 0; j < m; j++) {
            int c = matrix[i][j] - '0';
            x.push_back(c);
        }
        matrix1.push_back(x);
    }
    int sum = 0;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            sum += matrix1[i][j];
            if (matrix1[i][j] == 0) {
                sum = 0;
            }
            matrix1[i][j] = sum;
        }
        sum = 0;
    }
    vector<vector<int>> helper;

    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < m; j++) {
            v.push_back(matrix1[i][j]);
        }
        helper.push_back(v);
    }

    int max1 = 0;

    for (auto x : helper) {
        int ans = largestRectangleArea(x);
        max1 = max(max1 , ans);
    }

    return max1;
}
void solve() {
    int n , m; cin >> n >> m;

    vector<vector<char>> matrix;
    for (int i = 0; i < n; i++) {
        vector<char> x;
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            x.push_back(c);
        }
        matrix.push_back(x);
    }

    cout << maximalRectangle(matrix) << endl;    
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
