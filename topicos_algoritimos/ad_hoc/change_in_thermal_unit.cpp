#include <bits/stdc++.h>
#include <iomanip>
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

const double PI = 3.14159265358979323846;
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

inline double ctof(double c) { return 9.0 / 5.0 * c + 32.0; }
inline double ftoc(double f) { return (f - 32.0) * 5.0 / 9.0; }

int main() {
  _ ll t;
  cin >> t;
  ll caso{};
  while (t--) {
    ll c;
    cin >> c;
    ll f;
    cin >> f;
    double conv = ctof(c);
    conv += f;
    cout << "Case " << ++caso << ": ";
    cout << fixed << setprecision(2) << ftoc(conv);
    cout << '\n';
  }

  return 0;
}
