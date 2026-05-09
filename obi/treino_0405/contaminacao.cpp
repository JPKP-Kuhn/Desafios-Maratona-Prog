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
  _ ll n, m;
  while (cin >> n >> m && n && m) {
    vector<string> mat(n);
    queue<pl> verificar;

    vll dx = {0, 1, 0, -1};
    vll dy = {1, 0, -1, 0};

    for (ll i{}; i < n; i++) {
      cin >> mat[i];
      for (ll j{}; j < m; j++) {
        if (mat[i][j] == 'T')
          verificar.push({i, j});
      }
    }

    while (!verificar.empty()) {
      ll x = verificar.front().first;
      ll y = verificar.front().second;
      verificar.pop();

      for (ll d{}; d < 4; d++) {
        ll nx = x + dx[d];
        ll ny = y + dy[d];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          if (mat[nx][ny] == 'A') {
            verificar.push({nx, ny});
            mat[nx][ny] = 'T';
          }
        }
      }
    }

    for (ll i{}; i < n; i++) {
      cout << mat[i] << '\n';
    }
    cout << '\n';
  }

  return 0;
}
