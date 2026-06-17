#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

struct point {
  ll x, y;
  bool operator<(point other) const { return x < other.x; };
};

int main() {
  _ ll n;
  cin >> n;
  vector<point> v(n);
  for (point &p : v) {
    cin >> p.x >> p.y;
  }

  ll menory = LLONG_MAX;
  sort(all(v));
  ll c{0};
  for (ll i{0}; i < n; i++) {
    ll y = v[i].y;

    if (menory > y)
      c++;
    menory = min(menory, y);
  }

  cout << c << '\n';

  return 0;
}
