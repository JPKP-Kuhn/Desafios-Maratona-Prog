#include <bits/stdc++.h>
#include <unordered_map>
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
  _ ll n;
  cin >> n;
  vector<vll> mat(n, vll(n));
  for (vll &v : mat)
    for (ll &x : v)
      cin >> x;

  map<ll, ll> somas{};
  for (ll i{}; i < n; i++) {
    ll soma_linha{};
    ll soma_col{};
    for (ll j{}; j < n; j++) {
      soma_linha += mat[i][j];
      soma_col += mat[j][i];
    }
    somas[soma_linha]++;
    somas[soma_col]++;
  }
  if (somas.size() > 1)
    cout << -1 << '\n';
  else {
    ll sdip{}, sdsec{};
    for (ll i{}; i < n; i++) {
      sdip += mat[i][i];
      sdsec += mat[i][n - i - 1];
    }
    somas[sdip]++;
    somas[sdsec]++;

    if (somas.size() > 1) {
      cout << -1 << '\n';
    } else {
      cout << somas.begin()->first << '\n';
    }
  }

  return 0;
}
