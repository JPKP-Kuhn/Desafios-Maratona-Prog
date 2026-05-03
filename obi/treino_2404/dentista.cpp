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
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

int main() {
  _ ll n;
  cin >> n;
  vpll v;
  while (n--) {
    ll a, b;
    cin >> a >> b;
    v.pb({b, a});
  }
  sort(all(v));
  ll c{1};
  ll f = v[0].fr;
  for (ll i{1}; i < v.size(); i++) {
    auto [fim, ini] = v[i];
    if (ini >= f) {
      c++;
      f = fim;
    }
  }
  cout << c << '\n';

  return 0;
}
