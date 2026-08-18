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
  _ vector<string> mat(7);

  for (ll i{}; i < 7; i++) {
    cin >> mat[i];
  }

  vll dx = {1, 0, -1, 0};
  vll dy = {0, 1, 0, -1};
  vll fx = {2, 0, -2, 0};
  vll fy = {0, 2, 0, -2};

  ll c{};

  for (ll i{}; i < 7; i++) {
    for (ll j{}; j < 7; j++) {
      if (mat[i][j] == 'o') {
        for (ll d{}; d < 4; d++) {
          ll ny = i + dy[d];
          ll fuy = i + fy[d];
          ll nx = j + dx[d];
          ll fux = j + fx[d];

          if (nx >= 0 && nx < 7 && ny >= 0 && ny < 7 && fuy >= 0 && fuy < 7 &&
              fux >= 0 && fux < 7 && mat[ny][nx] == 'o' && mat[fuy][fux] == '.')
            c++;
        }
      }
    }
  }

  cout << c << '\n';

  return 0;
}
