#include <bits/stdc++.h>
#include <cstring>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

ll n;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  ll mat[n][3];
  ll dp [n][3];
  for (ll i=0; i<n; i++){
    for (ll j=0; j<3; j++){
      cin >> mat[i][j];
    }
  }

  dp[0][0] = mat[0][0];
  dp[0][1] = mat[0][1];
  dp[0][2] = mat[0][2];

  
  for (ll i=1; i<n; i++){
    ll a = max(dp[i-1][1], dp[i-1][2]);
    ll b = max(dp[i-1][0], dp[i-1][2]);
    ll c = max(dp[i-1][0], dp[i-1][1]);

    dp[i][0] = a + mat[i][0];
    dp[i][1] = b + mat[i][1];
    dp[i][2] = c + mat[i][2];
  }

  cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << '\n';

  return 0;
}

