#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

int main() {
  _ ll t;
  cin >> t;
  while (t--) {
    ll n, q;
    cin >> n >> q;
    vll a(n), b(n);
    for (ll &x : a)
      cin >> x;
    for (ll &y : b)
      cin >> y;

    vll best(n);
    for (ll i{}; i < n; i++) {
      best[i] = max(a[i], b[i]);
    }
    for (ll i = n - 2; i >= 0; i--) {
      best[i] = max(best[i], best[i + 1]);
    }

    vll psum(n + 1, 0);
    for (ll i{1}; i <= n; i++) {
      psum[i] = psum[i - 1] + best[i - 1];
    }

    while (q--) {
      ll l, r;
      cin >> l >> r;
      cout << psum[r] - psum[l - 1] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
