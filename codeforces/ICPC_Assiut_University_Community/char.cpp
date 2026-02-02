#include <bits/stdc++.h>
#include <cctype>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

// M_PI para número PI
const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo
const ll MOD = 1e9+7;    // Valor comum para aritmética modular, números muito grandes
const ll EPS = -1e9;     // Valor para comparar double

struct point {
  double x, y;
  point() {x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator < (point other) const {
    if (fabs(x - other.x) > EPS)
      return x < other.x;
    return y < other.y;
  };
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char c; cin >> c;
  if (c >= 'A' and c <= 'Z') cout << static_cast<char>(tolower(c)) << '\n';
  else cout << static_cast<char>(toupper(c)) << '\n';

  return 0;
}

