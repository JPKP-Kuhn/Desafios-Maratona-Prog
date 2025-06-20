#include <bits/stdc++.h>
#include <cstdint>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;
 

const int64_t MOD = 1e9 + 7;
 
int64_t pd[MOD];
bool found[MOD];
 
ll dp(ll n){
  if (found[n]) return pd[n];
  if (n == 0) return 0;
  if (n == 1) return 1;

  found[n] = true;
  return pd[n] = (dp(n-1) + dp(n-2))%MOD;
 
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  ll n{};
  cin >> n;
 
  pd[0] = 0;
  pd[1] = 1;
 
  int64_t fib = dp(n);
  cout << fib << '\n';
 
  return 0;
}
