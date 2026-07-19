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

int main() {
  _ ll n;
  cin >> n;
  vll v(n);
  for (ll &x : v)
    cin >> x;

  ll ans = v[0];
  ll maxEnd = v[0];

  for (ll i = 1; i < n; i++) {
    maxEnd = max(v[i], maxEnd + v[i]);
    ans = max(ans, maxEnd);
  }
  cout << ans << '\n';

  return 0;
}
