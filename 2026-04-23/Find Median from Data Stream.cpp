#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

struct myDS {
    int count = 0;
    multiset<double> smaller; multiset<double> larger;
    void balance () {
        if (smaller.size() < larger.size()) {
            int ans1 = *larger.begin(); smaller.insert(ans1);
            larger.erase(larger.begin());
        }
        if (larger.size() + 1 < smaller.size()) {
            int ans1 = *smaller.rbegin(); larger.insert(ans1);
            smaller.erase(prev(smaller.end()));
        }
    }
    void insert(int x) {
        count ++;
        if (smaller.size() == 0 && larger.size() == 0) {
            smaller.insert(x);
        }
        else {
            int ans1 = *smaller.rbegin();
            if (x <= ans1) {
                smaller.insert(x);
            }
            else larger.insert(x);
        }
        balance();
    }
    double getMedian() {
        if (count % 2 == 1) {
            return *smaller.rbegin();
        }
        else {
            int ans1 = *smaller.rbegin();int ans2 = *larger.begin();
            return (ans1 + ans2) / 2.0;
        }
    }
};
void solve() {
    myDS ds;
    ds.insert(-1);
    ds.insert(-2);
    cout << ds.getMedian();
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
