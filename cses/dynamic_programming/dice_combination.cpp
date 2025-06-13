#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MOD = pow(10, 9) + 7;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

ll pd(ll n){
  vll dp(n+1, 0);

  dp[0] = 1;

  for (ll i=1; i<n+1; i++){
    for (ll dado=1; dado<7; dado++){
      if (i >= dado){
        dp[i] = (dp[i] + dp[i-dado]) % MOD;
      }
    }
  }

  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n{};
  cin >> n;
  cout << pd(n) << '\n';

  return 0;
}

