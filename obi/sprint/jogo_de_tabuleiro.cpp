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

int main() {
  _ ll n;
  cin >> n;
  vector<vll> mat(n, vll(n));

  for (ll i{}; i < n; i++) {
    for (ll j{}; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  for (ll i{1}; i < n; i++) {
    for (ll j{1}; j < n; j++) {
      unordered_map<ll, ll> q;
      ll ci = mat[i - 1][j];
      ll ce = mat[i][j - 1];
      ll di = mat[i - 1][j - 1];
      q[ci]++;
      q[ce]++;
      q[di]++;

      if (q[1] > q[0])
        mat[i][j] = 0;
      else
        mat[i][j] = 1;
    }
  }

  cout << mat[n - 1][n - 1] << '\n';
  return 0;
}
