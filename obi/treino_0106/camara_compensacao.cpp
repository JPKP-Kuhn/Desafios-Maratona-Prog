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

int main() {
  _ ll m, n;
  cin >> m >> n;

  vll saldo(n + 1);

  ll soma{};
  while (m--) {
    ll a, v, b;
    cin >> a >> v >> b;
    saldo[a] -= v;
    saldo[b] += v;
    soma += v;
  }

  ll minimo{};
  for (ll s : saldo) {
    if (s > 0)
      minimo += s;
  }
  if (minimo < soma) {
    cout << "S\n" << minimo << '\n';
  } else {
    cout << "N\n" << soma << '\n';
  }

  return 0;
}
