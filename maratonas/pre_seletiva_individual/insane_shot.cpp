#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

const double EPS = 1e-4; // Valor para comparar double

struct vetor {
  double x, y;

  double compr() const { return sqrt(x * x + y * y); }

  vetor operator+(const vetor &other) const {
    return {x + other.x, y + other.y};
  }

  vetor operator-(const vetor &other) const {
    return {x - other.x, y - other.y};
  }

  vetor operator*(double k) const { return {x * k, y * k}; }

  vetor operator/(double other) const { return {x / other, y / other}; }
};

int main() {
  _ vetor ctank;
  ll raio;
  cin >> ctank.x >> ctank.y >> raio;
  vetor sher;
  cin >> sher.x >> sher.y;
  vetor enemy;
  cin >> enemy.x >> enemy.y;

  vetor difu = sher - ctank;
  vetor u = difu / difu.compr();

  vetor difv = enemy - ctank;
  vetor v = difv / difv.compr();

  vetor soma = u + v;

  if (soma.compr() < EPS) {
    cout << "No way\n";
    return 0;
  }
  vetor n = soma / soma.compr();

  double x1 = ctank.x + n.x * raio;
  double y1 = ctank.y + n.y * raio;

  cout << fixed << setprecision(6) << x1 << ' ' << y1 << '\n';

  return 0;
}
