//https://leetcode.com/problems/zigzag-conversion/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long


string convert(string s, int numRows) {
    if (numRows == 1) return s;

    if (numRows == 2) {
        string ans;
        for (int i = 0; i < s.length(); i += 2) ans += s[i];
        for (int i = 1; i < s.length(); i += 2) ans += s[i];
        return ans;
    }

    int n = numRows; string temp; string ans;
    vector<string> helper;
    int numCols = numRows - 2;

    for (int i = 0; i < n; i++) temp += '0';

    int count = 0 , count1 = 0; int flip = 1; string z = temp;
    int index2 = numRows - 2;

    for (int i = 0; i < s.length(); i++) {
        if (flip == 1) {
            z[count] = s[i];
            count ++;
            
            if (i == s.length() - 1) {
                helper.push_back(z);
                break;
            }
            if (count == numRows) {
                count = 0;
                helper.push_back(z);
                flip = 0; z = temp;
            }
        }
        else if (flip == 0) {
            z = temp;
            z[index2] = s[i];
            helper.push_back(z); index2 --; count1 ++;
            if (count1 == numCols) {
                flip = 1;
                z = temp;
                index2 = numRows - 2;
                count1 = 0;
            }
        }
    }
    for (auto x:helper) cout << x << endl;

    for (int i = 0; i < helper[0].size(); i++) {
        for (int j = 0; j < helper.size(); j++) {
            if (helper[j][i] != '0') ans += helper[j][i];
        }
    }

    return ans;
}
void solve() {
    string s; cin >> s; int r; cin >> r;
    string ans = convert(s , r); 
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
