#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll MOD = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vll dp(n+1, 0);
  dp[0] = 1;
  for (ll i = 1; i<n+1; i++){
    for (ll dado = 1; dado < 7; dado++){
      if (i >= dado){
        dp[i] = (dp[i] + dp[i-dado]) % MOD;
      }
    }
  }
  ll c = dp[n] % MOD;
  cout << c << '\n';

  return 0;
}

