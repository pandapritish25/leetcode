//https://leetcode.com/problems/closest-prime-numbers-in-range/description/
#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> sieve(int n) {
  int*arr = new int[n + 1](); 
  vector<int> vect; 
  for (int i = 2; i <= n; i++) {
    if (arr[i] == 0) {
      vect.push_back(i); for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    } 
  }
  return vect;
}

vector<int> closestPrimes(int left, int right) {
   vector<int> primes = sieve(3000006);
   int index_ans1 = lower_bound(primes.begin() , primes.end() , left) - primes.begin();
   int index_ans2 = index_ans1 + 1;
   int ans1 = primes[index_ans1]; int ans2 = primes[index_ans2];
   vector<int> x = {-1 , -1};
   int min1 = INT_MAX;
   vector<int> ans;

   if (ans1 >= left && ans1 <= right && left <= right && ans2 >= left && ans2 <= right) {
        int xx = 0 , yy = 0; 
        index_ans1 = lower_bound(primes.begin() , primes.end() , left) - primes.begin();
        int index_ans3 = lower_bound(primes.begin() , primes.end() , right) - primes.begin();
        
        for (int i = index_ans1; i <= index_ans3; i++) {
            if (primes[i] >= right) break;
            int diff = primes[i + 1] - primes[i];
            if (diff < min1) {
                min1 = diff; xx = primes[i]; yy = primes[i + 1];
            } 
        }   
        ans.push_back(xx);ans.push_back(yy);
        return ans;
   }
   return x;
}

void solve() {
    int l , r; cin >> l >> r;
    vector<int> ans = closestPrimes(l , r);
    for (auto x : ans) cout << x << " ";
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
