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
  cin >> n >> m;
  vector<string> mat(n);
  pl ini;
  for (ll i{}; i < n; i++) {
    cin >> mat[i];
    if (i == 0) {
      for (ll j{}; j < m; j++) {
        if (mat[i][j] == 'o') {
          ini.first = i;
          ini.second = j;
        }
      }
    }
  }

  queue<pl> fila;
  fila.push(ini);

  while (!fila.empty()) {
    ll x = fila.front().first;
    ll y = fila.front().second;
    fila.pop();

    if (x >= 0 && x < n && y >= 0 && y < m) {
      // verifica abaixo
      if (x + 1 < n && mat[x + 1][y] == '.') {
        mat[x + 1][y] = 'o';
        fila.push({x + 1, y});
        // verifica direita da estante
      }
      if (x + 1 < n && y + 1 < m && mat[x][y + 1] == '.' &&
          mat[x + 1][y] == '#') {
        mat[x][y + 1] = 'o';
        fila.push({x, y + 1});
        // verifica esquerda da estante
      }
      if (x + 1 < n && y - 1 >= 0 && mat[x][y - 1] == '.' &&
          mat[x + 1][y] == '#') {
        mat[x][y - 1] = 'o';
        fila.push({x, y - 1});
      }
    }
  }

  for (ll i{}; i < n; i++) {
    cout << mat[i] << '\n';
  }

  return 0;
}
