//https://leetcode.com/problems/reverse-integer/description/?envType=problem-list-v2&envId=math
// basically you would be needing to reverse a number without any 64 bit nums
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";

// in case of when the no of digits is 10 , if no is more than 0 compare with INT_MAX
// if no is less than 0 compare with INT_MIN
bool check(int n1) {
    string s1 = to_string(n1);
    // in case this is more than 0 and count == 10 , if pos then we would be needing 10
    if (n1 > 0) {
        if (s1.length() < 10) return true;
        if (s1.length() > 10) return false;
    }
    // if negative , one - will be included and we will be having the ans as 11
    if (n1 < 0) {
        if (s1.length() < 11) return true;
        if (s1.length() > 11) return false;
    }
    // then you have convert INT_MAX and INT_MIN to Strings
    string INT_MAX1 = to_string(INT_MAX); string INT_MIN1 = to_string(INT_MIN);
    int n = s1.length();
    reverse(s1.begin() , s1.end()); bool ok = true;

    // if more than 0 compare with INT_MAX
    if (n1 > 0) {
        for (int i = 0; i < n; i++) {
            if (s1[i] == INT_MAX1[i]) continue;
            int x1 = s1[i] - '0'; int x2 = INT_MAX1[i] - '0';
            // if first digit is more then we dont have the ans
            if (x1 > x2) {
                ok = false; break;
            }
            // else we would be having the ans
            if (x1 < x2) {
                ok = true; break;
            }
        }
    }
    // same goes when n < 0
    if (n1 < 0) {
        // only we need to remove - from s1 and then insert at front
        s1.insert(s1.begin() + 0 , '-'); s1.pop_back();
        for (int i = 0; i < n; i++) {
            if (s1[i] == INT_MIN1[i]) continue;
            int x1 = s1[i] - '0'; int x2 = INT_MIN1[i] - '0';
            // same logic encountering the first digit
            if (x1 > x2) {
                ok = false; break;
            } 
            if (x1 < x2) {
                ok = true; break;
            }
        }
    }
    // returning the ans
    return ok;
}
int reverse(int x) {
    if (x == 0) return 0;

    int max_range = INT_MAX; int min_range = INT_MIN;
    
    int count = 0; int temp = x; int nums = 0;
    while (temp > 0) {
        temp = temp / 10; count ++;
    }
    bool ans1 = check(x);
    if (ans1 == false) return 0;

    temp = x;
    // insted of doing nums > 0 always do nums != 0 works fine with neg nos as well

    while(temp != 0) {
        int rem = temp % 10; temp = temp / 10;
        nums = nums * 10 + rem;
    }
    return nums;
}

void solve() {
    int n; cin >> n;
    cout << reverse(n) << endl;
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
