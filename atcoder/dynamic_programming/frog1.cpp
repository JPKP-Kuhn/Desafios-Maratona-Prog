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

const ll MAXN = 1e6 + 7;

vll dp;
vll v;

ll solve(ll n) {
  if (dp[n] != -1)
    return dp[n];

  dp[n] = min(solve(n - 1) + abs(v[n - 1] - v[n]),
              solve(n - 2) + abs(v[n - 2] - v[n]));

  return dp[n];
}

int main() {
  _ ll n;
  cin >> n;
  v.resize(n);
  dp.assign(n, -1);
  for (ll &x : v)
    cin >> x;
  dp[0] = 0;
  dp[1] = abs(v[0] - v[1]);

  cout << solve(n - 1) << '\n';

  return 0;
}
