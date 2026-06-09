#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

const ll INF = 1e18 + 19;

int main() {
  _ ll n, k;
  cin >> n >> k;
  vll v(n), dp(n, INF);

  for (ll &x : v)
    cin >> x;

  dp[0] = 0;
  dp[1] = abs(v[0] - v[1]);
  for (ll i{}; i < n; i++) {
    for (ll j = 1; j <= k; j++) {
      if (i - j >= 0) {
        dp[i] = min(dp[i], dp[i - j] + abs(v[i] - v[i - j]));
      }
    }
  }

  cout << dp[n - 1] << '\n';

  return 0;
}
