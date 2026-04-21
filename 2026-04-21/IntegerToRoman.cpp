//https://leetcode.com/problems/integer-to-roman/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

string intToRoman(int num) {
    map<int,string> mp;
    mp[1] = "I"; mp[5] = "V"; mp[10] = "X"; mp[50] = "L"; mp[100] = "C"; mp[500] = "D"; mp[1000] = "M";
    int temp = num; string ans;

    string x1 = to_string(num);

    int ans1 = x1.back() - '0';
    if (ans1 == 1) ans += mp[ans1];
    else if (ans1 == 5) ans += mp[ans1];
    else if (ans1 == 4) ans += "VI";
    else if (ans1 == 3) ans += "III";
    else if (ans1 == 2) ans += "II";
    else if (ans1 == 6) ans += "IV";
    else if (ans1 == 7) ans += "IIV";
    else if (ans1 == 8) ans += "IIIV";
    else if (ans1 == 9) ans += "XI";

    if (x1.size() == 1) {
        reverse(ans.begin() , ans.end()); return ans;
    }

    int n = x1.size();
    ans1 =  x1[n - 2] - '0'; 

    if (ans1 == 1) ans += "X";
    if (ans1 == 2) ans += "XX";
    if (ans1 == 3) ans += "XXX";
    if (ans1 == 4) ans += "LX";
    if (ans1 == 5) ans += "L";
    if (ans1 == 6) ans += "XL";
    if (ans1 == 7) ans += "XXL";
    if (ans1 == 8) ans += "XXXL";
    if (ans1 == 9) ans += "CX";
    
    if (x1.size() == 2) {
        reverse(ans.begin() , ans.end()); return ans;
    }
    ans1 =  x1[n - 3] - '0';
    if (ans1 == 1) ans += "C";
    if (ans1 == 2) ans += "CC";
    if (ans1 == 3) ans += "CCC";
    if (ans1 == 4) ans += "DC";
    if (ans1 == 5) ans += "D";
    if (ans1 == 6) ans += "CD";
    if (ans1 == 7) ans += "CCD";
    if (ans1 == 8) ans += "CCCD";
    if (ans1 == 9) ans += "MC";

    if (x1.size() == 3) {
        reverse(ans.begin() , ans.end()); return ans;
    }
    ans1 = x1[0] - '0';
    if (ans1 == 1) ans += "M";
    if (ans1 == 2) ans += "MM";
    if (ans1 == 3) ans += "MMM";
    if (x1.size() == 4) {
        reverse(ans.begin() , ans.end()); return ans;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    cout << intToRoman(n) << endl;
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
