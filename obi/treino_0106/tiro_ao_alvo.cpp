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
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

int main() {
  _ ll c, t;
  cin >> c >> t;
  ll pontos{};
  vll r2(c);
  for (ll i{}; i < c; i++) {
    ll r;
    cin >> r;
    r2[i] = r * r;
  }

  while (t--) {
    ll x, y;
    cin >> x >> y;
    ll d2 = x * x + y * y;

    vll::iterator it = lower_bound(all(r2), d2);

    pontos += r2.end() - it;
  }

  cout << pontos << '\n';

  return 0;
}
