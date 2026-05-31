#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define fr first
using ll = long long;
using vll = vector<ll>;

// M_PI para número PI
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

struct point {
  ll x, y;
};

void print128(__int128 x) {
  if (x == 0) {
    cout << 0;
    return;
  }

  string s;

  while (x > 0) {
    s.push_back('0' + x % 10);
    x /= 10;
  }

  reverse(s.begin(), s.end());
  cout << s;
}

__int128 polygonArea(vector<point> &v) {
  __int128 area = 0;
  ll n = v.size();
  // shoelace formula
  ll j = n - 1;
  for (ll i{}; i < n; i++) {
    area += (__int128)v[j].x * v[i].y - (__int128)v[j].y * v[i].x;
    j = i;
  }
  if (area < 0)
    area = -area;
  return area;
}

int main() {
  _ ll n;
  cin >> n;
  vector<point> v(n);
  for (point &p : v) {
    cin >> p.x >> p.y;
  }

  __int128 area = polygonArea(v);
  print128(area);
  cout << '\n';

  return 0;
}
