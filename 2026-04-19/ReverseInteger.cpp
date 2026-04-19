//https://leetcode.com/problems/reverse-integer/description/
// This problem can be used only when we are having integers this checks has been only implemented because of integers 
#include<bits/stdc++.h>
using namespace std;
#define int long long

int check1(int n) {
   string ans1 = to_string(n);
   if (n > 0 && ans1.length() < 10) return true;
   if (n < 0 && ans1.length() < 11) return true;
   return false;
}
int check(int n) {
    string ans1 = to_string(n);
    if (n > 0 && ans1.length() == 10) return true;
    if (n < 0 && ans1.length() == 11) return true;
    return false; 
} 

bool return_pos_int(int n) {
    string ans1 = to_string(n);reverse(ans1.begin() , ans1.end());
    string ans2 = to_string(INT_MAX);
    cout << ans1 << " " << ans2 << endl;
    for (int i = 0; i < ans1.length(); i++) {
        if (ans1[i] == ans2[i]) continue;
        int xx = ans1[i] - '0'; int yy = ans2[i] - '0';
        if (xx > yy) return false;
        else return true;
    }
    return false;
} 
bool return_pos_neg(int n) {
    string ans1 = to_string(n);reverse(ans1.begin() , ans1.end());
    ans1.pop_back(); ans1.insert(ans1.begin() , '-');
    string ans2 = to_string(INT_MIN);

    for (int i = 0; i < ans1.length(); i++) {
        if (ans1[i] == ans2[i]) continue;
        int xx = ans1[i] - '0'; int yy = ans2[i] - '0';
        if (xx > yy) return false;
        else return true;
    }
    return false;
}   

int reverse1(int n) {
    int temp = n; int ans = 0;

    while(temp != 0) {
        ans = (ans * 10) + (temp % 10);
        temp /= 10;
    }
    return ans;
}

int reverse(int x) {
    if (x == 0) return 0;
    if (check1(x)) {
        return reverse1(x);
    }
    if (check(x)) {
        if (x > 0 && return_pos_int(x)) return reverse1(x);
        if (x < 0 && return_pos_neg(x)) return reverse1(x);
    }
    return 0;
}
void solve() {
    int n; cin >> n; cout << reverse(n) << endl;
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
