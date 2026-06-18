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

const double EPS = 1e-9; // Valor para comparar double

int main() {
  _ ll cx, cy, raio;
  cin >> cx >> cy >> raio;

  ll sx, sy, ex, ey;
  cin >> sx >> sy >> ex >> ey;

  double mx = (double)(ex + sx) / 2.0;
  double my = (double)(ey + sy) / 2.0;

  double ux = mx - (double)cx;
  double uy = my - (double)cy;
  double tam = sqrt(ux * ux + uy * uy);

  if (tam - raio < EPS) {
    cout << "No way\n";
    return 0;
  }

  double umx = ux / tam;
  double umy = uy / tam;

  double ansx, ansy;
  ansx = cx + umx * raio;
  ansy = cy + umy * raio;

  cout << fixed << setprecision(6) << ansx << ' ' << ansy << '\n';

  return 0;
}
