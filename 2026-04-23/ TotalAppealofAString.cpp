//https://leetcode.com/problems/total-appeal-of-a-string/description/
#include <bits/stdc++.h>
using namespace std;

long long calculate(vector <long long> v , int n) {
    if (v.size() == 1) {
        long long curr_val = v[0];
        long long tot_contribution = (n - curr_val) * (curr_val + 1); 
        return tot_contribution;
    }
    long long tot_contribution = 0;long long curr_contribution = 0;

    for (long long i = 0; i < v.size(); i++) {
        if (i == 0) {
            curr_contribution = (n - v[0]) * (v[0] + 1);
            tot_contribution += curr_contribution;
            continue;
        }
        long long ans1 = v[i - 1] + 1;
        long long no_of_elements = n - ans1;
        long long partation = v[i] - ans1;
        curr_contribution = (no_of_elements - partation) * (partation + 1);
        tot_contribution += curr_contribution;
    }
    return tot_contribution;
}
long long appealSum(string s) {
    long long n = s.length(); map<char , vector<long long>> mp;
    long long calc = 0;
    for (long long i = 0; i < n; i++)  mp[s[i]].push_back(i);
    for (auto x : mp)  calc += calculate(x.second , n);

    // cout << calc << endl;
    return calc;
}

signed main() {
    string s; cin >> s; 
    cout << appealSum(s) << endl;
}