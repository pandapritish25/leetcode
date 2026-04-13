//https://leetcode.com/problems/unique-paths/description/?envType=problem-list-v2&envId=math
// This needs to be resolved by DP actually , I have take this in combinatroics
// this needs to be solved once more
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";

int MOD = 1e9 + 7;
int mod_mul(int a , int b) {
  int ans1 = a % MOD; int ans2 = b % MOD;
  int ans3 = (((ans1 * ans2) % MOD) + MOD) % MOD; 
  return ans3;
}
int binpow(int a , int b) {
  if (b == 0) return 1;

  if (b % 2 == 1) {
    int ans1 = mod_mul(a , binpow(a , b - 1));
    return ans1;
  }
  
  if (b % 2 == 0) {
    int ans1 = binpow(a , b / 2);
    return mod_mul(ans1 , ans1);
  }
  return 0;
}
int MAXN_FACTO = 1e5 + 2;
vector <int> facto(MAXN_FACTO);
vector <int> inv_facto(MAXN_FACTO);

void precompute_factorial() {
  facto[0] = 1;
  int max_compute = MAXN_FACTO; int ans = 1;
  for (int i = 1; i <= max_compute; i++) facto[i] = mod_mul(facto[i - 1] , i);
}
int inverse(int n) {
    return binpow(n , MOD - 2);
}
void precompute_inverseFactorial(){
  for (int i = 0; i < facto.size(); i++) inv_facto[i] = (inverse(facto[i]) % MOD);
}

int ncr(int n , int r) {
  int ans1 = mod_mul(facto[n] , inv_facto[r]);
  ans1 = mod_mul(ans1 , inv_facto[n - r]);
  return ((ans1 % MOD) + MOD) % MOD;
}
int uniquePaths(int m, int n) {
    m --; n --;
    int sum = m + n;
    return ncr(sum , m);
}
void solve() {
    int n , m; cin >> n >> m;
    cout << uniquePaths(n , m) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1;     
    precompute_factorial();
    precompute_inverseFactorial();
    // cin >> t;
    while (t --) {
        solve();
    }
}
