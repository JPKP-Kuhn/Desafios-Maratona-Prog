#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
    vll domino(n);
    for (ll i=0; i<n; i++){
      cin >> domino[i];
    }

    vll dp(n, INF);
    dp[0]=1;

    for (ll i=0; i<n; i++){
      if (dp[i] == INF) continue;

      for (ll j=i+1; j<n; j++){
        if (domino[j] <= 2 * domino[i])
          dp[j]= min(dp[j], dp[i]+1);
      }
    }

    if (dp[n-1] == INF){
      cout << -1 << '\n';
    } else {
      cout << dp[n-1] << '\n';
    }
  }

  return 0;
}

