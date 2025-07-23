#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

ll n;
vll num(MAXN);
vll dp(MAXN, -1);
ll pd(ll i){
  if (i == 0) return 0;
  if (i == 1) return abs(num[0] - num[1]);
  if (dp[i] != -1) return dp[i];
  dp[i] = min(abs(num[i] - num[i-1]) + pd(i-1), abs(num[i] - num[i-2]) + pd(i-2));

  return dp[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (ll i=0; i<n; i++){
    cin >> num[i];
  }

  dp[0] = 0;
  dp[1] = abs(num[0] - num[1]);
  ll ans = pd(n-1);

  cout << ans << '\n';

  return 0;
}

