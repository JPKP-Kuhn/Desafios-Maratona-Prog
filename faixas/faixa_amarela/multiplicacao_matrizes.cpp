#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  ll p, q, r, s, x, y;
  cin >> p >> q >> r >> s >> x >> y;
  ll idx, idy;
  cin >> idx >> idy;

  ll ans{};
  for (ll k=1; k<=n; k++){
    ll a = (p * idx + q * k) % x;
    ll b = (r * k + s * idy) % y;
    ans += a * b;
  }

  cout << ans << '\n';
  return 0;
}

