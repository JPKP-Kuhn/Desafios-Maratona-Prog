#include <bits/stdc++.h>
#include <queue>
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

// M_PI para número PI
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

struct point {
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator<(point other) const {
    if (fabs(x - other.x) > EPS)
      return x < other.x;
    return y < other.y;
  };
};

int main() {
  _ ll n, k;
  cin >> n >> k;
  vector<vll> mat(n, vll(n, -1));

  vector<tuple<ll, ll, ll>> pos;
  while (k--) {
    ll x, y, d;
    cin >> x >> y >> d;
    pos.push_back({d, x, y});
  }

  ll c{}, ansX = -1, ansY = -1;
  for (ll i{}; i < n; i++) {
    for (ll j{}; j < n; j++) {
      bool ok = true;
      for (auto &[dist, x, y] : pos) {
        ll d = abs(i - x) + abs(j - y);

        if (d != dist) {
          ok = false;
          break;
        }
      }
      if (ok) {
        c++;
        ansX = i;
        ansY = j;
      }
    }
  }

  if (c == 1) {
    cout << ansX << ' ' << ansY << '\n';
  } else {
    cout << -1 << ' ' << -1 << '\n';
  }

  return 0;
}
