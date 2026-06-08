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

using ll = long long;
using vll = vector<ll>;

const double EPS = 1e-9; // Valor para comparar double

struct point {
  ll x, y;
  point() { x = y = 0.0; }
  point(ll _x, ll _y) : x(_x), y(_y) {}
  bool operator<(point other) const {
    if (fabs(x - other.x) > EPS)
      return x < other.x;
    return y < other.y;
  };
};

ll gcd(ll a, ll b) {
  while (b) {
    ll t = a % b;
    a = b;
    b = t;
  }
  return a;
}
pair<ll, ll> slope(point a, point b) {
  ll dy = b.y - a.y;
  ll dx = b.x - a.x;

  if (dx == 0)
    return {1, 0}; // vertical

  if (dy == 0)
    return {0, 1}; // horizontal

  ll g = gcd(abs(dx), abs(dy));

  dx /= g;
  dy /= g;

  if (dx < 0) {
    dx *= -1;
    dy *= -1;
  }

  return {dy, dx};
}

int main() {
  _ ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<point> v(n);
    for (ll i{}; i < n; i++) {
      ll x, y;
      cin >> x >> y;
      v[i].x = x;
      v[i].y = y;
    }

    ll ans = min(1LL, n);

    for (ll i{}; i < n; i++) {
      map<pair<ll, ll>, ll> freq;

      for (ll j = i + 1; j < n; j++) {
        auto s = slope(v[i], v[j]);

        freq[s]++;

        ans = max(ans, freq[s] + 1);
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
