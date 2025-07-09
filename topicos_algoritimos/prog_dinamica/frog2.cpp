#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

ll n, k;
vll num(MAXN), dp(MAXN, INF);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for (ll i=0; i<n; i++){
    cin >> num[i];
  }

  dp[0] = 0;
  for (ll i=1; i<n; i++){
    for (ll j=1; j<=k; j++){
      if (i - j >= 0){
        dp[i] = min(dp[i], dp[i-j] + abs(num[i] - num[i-j]));
      }
    }
  }

  cout << dp[n-1] << '\n';

  return 0;
}

