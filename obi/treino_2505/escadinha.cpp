#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

int main() {
  _ ll n;
  cin >> n;

  vll v(n);
  for (ll &x : v)
    cin >> x;

  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }

  ll c{1};
  ll r = v[1] - v[0];
  for (ll i{2}; i < n; i++) {
    ll atual = v[i] - v[i - 1];

    if (atual != r) {
      c++;
      r = atual;
    }
  }

  cout << c << '\n';

  return 0;
}
