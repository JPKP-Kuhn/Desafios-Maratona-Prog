#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll fib(ll x, vll &dp){
  if (dp[x] != -1) return dp[x];

  dp[x] = fib(x-1, dp) + fib(x-2, dp);
  return dp[x];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll x; cin >> x;
  vll dp(50, -1);
  dp[0]=0;
  dp[1]=1;

  for (ll i{}; i<x; i++){
    cout << fib(i, dp) << ' ';
  }
  cout << '\n';

  return 0;
}

