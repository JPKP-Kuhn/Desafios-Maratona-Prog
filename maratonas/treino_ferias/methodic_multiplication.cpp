#include <algorithm>
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

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

int main() {
  _ string a, b;
  cin >> a >> b;
  ll na = count(all(a), 'S');
  ll nb = count(all(b), 'S');

  ll r = na * nb;
  if (r == 0) {
    cout << 0 << '\n';
    return 0;
  }

  string ans;
  for (ll i{}; i < r; i++) {
    ans += "S(";
  }
  ans += "0";
  for (ll i{}; i < r; i++) {
    ans += ')';
  }
  cout << ans << '\n';

  return 0;
}
