//https://leetcode.com/problems/multiply-strings/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

string multiply(string num1, string num2) {
    if (num1.length() < num2.length()) swap (num1 , num2);
    vector<string> v; string zeros; int count = 0; int max1 = 0;
    if (num1 == "0" || num2 == "0") return "0";

    for (int i = num2.length() - 1; i >= 0; i --) {
        int x = num2[i] - '0'; int carry = 0; string form;
        for (int j = num1.length() - 1; j >= 0; j--) {
            int x1 = num1[j] - '0'; int prod = x1 * x;
            if (j != 0) {
                prod = prod + carry;
                form += (prod % 10) + '0';
                carry = prod / 10;
            } 
            if (j == 0) {
                prod = prod + carry;
                string y = to_string(prod); reverse(y.begin() , y.end());
                form += y;
            }
        }
        reverse(form.begin() , form.end());
        for (int j = 0; j < count; j++) form += '0';
        count ++; v.push_back(form);
    }
    for (int i = 0; i < v.size(); i++) {
        int z = v[i].length(); max1 = max(max1 , z);
    }
    for (int i = 0; i < v.size(); i++) {
        string y1 = v[i];
        int need = max1 - y1.length();
        for (int j = 0; j < need; j++) y1.insert(y1.begin() , '0');
        v[i] = y1;
    }
    int x2 = v[0].size();

    int carry = 0; string ans;
    for (int j = x2 - 1; j >= 0; j--) 
    {
        if (j != 0) {
            int sum = 0;
            for (int i = 0; i < v.size(); i++) {
                int curr = (v[i][j] - '0');
                sum += curr; 
            }
            sum += carry;
            ans += (sum % 10) + '0';
            carry = sum / 10;
        }
        if (j == 0) {
            int sum = 0;
            for (int i = 0; i < v.size(); i++) {
                int curr = (v[i][j] - '0');
                sum += curr; 
            }
            sum += carry;
            string ty = to_string(sum); reverse(ty.begin() , ty.end());
            ans += ty;
        }
    }
    reverse(ans.begin() , ans.end());
    // cout << ans << endl;
    return ans;
}
void solve() {
    string x , y; cin >> x >> y;
    string ans = multiply(x , y);
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
