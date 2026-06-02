#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

const double pi = 3.141592;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll theta, n;
  cin >> theta >> n;
  // line sweep
  vector<pair<double, double>> cf(n);
  for (ll i = 0; i < n; i++) {
    ll h, x;
    cin >> x >> h;
    // SOHCAHTOA
    // pi/x = 180/theta
    // pi theta)/180
    double chao = (double)h / tan((pi * theta) / 180.0);
    cf[i] = make_pair((double)x, (double)x + chao);
  }
  vector<pair<double, double>> sl;
  for (pair<double, double> p : cf) {
    sl.push_back({p.first, 1});
    sl.push_back({p.second, -1});
  }
  ll cont{};
  double ans{};
  sort(sl.begin(), sl.end());
  double last{};

  for (auto [x, tipo] : sl) {
    if (cont > 0)
      ans += x - last;
    cont += tipo;
    last = x;
  }
  cout << fixed << setprecision(14) << ans << '\n';
  return 0;
}
