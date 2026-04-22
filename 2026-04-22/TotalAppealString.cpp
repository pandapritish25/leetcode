//https://leetcode.com/problems/total-appeal-of-a-string/description/

#include<bits/stdc++.h>
using namespace std;

long long calc(vector<long long> v , long long n) {
    long long sum = 0;
    for (long long i = 0; i < v.size(); i++) {
        if (i == 0) {
            long long prod = (n - v[0]) * (v[0] + 1);
            sum += prod; continue;
        }
        long long ele1 = v[i] - (v[i - 1] + 1);
        long long ele2 = n - v[i];
        long long ele = ele1 + ele2;
        long long prod = (ele - ele1) * (ele1 + 1);
        sum += prod;
    }
    return sum;
}
long long appealSum(string s) {
    map <char , vector<long long>> helper;
    long long n = s.length();
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        helper[s[i]].push_back(i);
    }
    for (auto i : helper) {
        ans += calc(i.second , n);
    }
    return ans;
}
signed main() {
    string s; cin >> s; cout << appealSum(s) << endl;
}