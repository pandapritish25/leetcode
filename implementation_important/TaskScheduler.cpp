#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int leastInterval(vector<char>& tasks, int k) {
    int n = tasks.size(); int max_freq = 0 , count = 0;

    vector<int> occ(26 , 0);

    for (int i = 0; i < n; i++) occ[tasks[i] - 'A'] ++;

    for (int i = 0; i < occ.size(); i++) {
        if (occ[i] > max_freq) {
            max_freq = occ[i];
            count = 1;
        }
        else if (occ[i] == max_freq) count ++;
    }

    int slots = (max_freq - 1) * k + max_freq;
    slots += (count - 1);

    slots = max(slots , n);
    return slots;
}
// just for better functionality
int leastInterval1(vector<char>& tasks, int k) {
    int n = tasks.size(); int count = 0 , max1 = 0;
    vector<int> occ(26 , 0);

    for (int i = 0; i < n; i++) occ[tasks[i] - 'A'] ++;
    max1 = *max_element(occ.begin() , occ.end());


    for (int i = 0; i < occ.size(); ++i) if (occ[i] == max1) count ++;
    int slots = (max1 - 1) * k;
    slots += max1; slots += (count - 1);

    return max(slots , n);
}

void solve() {
    int n; cin >> n; int k; cin >> k;
    vector<char> tasks;

    for (int i = 0; i < n; i++) {
        char x; cin >> x;
        tasks.push_back(x);
    }

    cout << leastInterval(tasks , k) << endl;
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
