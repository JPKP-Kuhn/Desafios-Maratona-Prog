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

using ll = int;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

int main() {
  _ ll n, q;
  cin >> n >> q;
  vll a(n);

  ll block = sqrt(n) + 1;
  ll blocks = (n + block - 1) / block;
  vector<vll> b(blocks, vll(100001));

  for (ll i{}; i < n; i++) {
    cin >> a[i];
    b[i / block][a[i]]++;
  }

  while (q--) {
    ll o;
    cin >> o;
    if (o == 1) { // alteração
      ll x, w;
      cin >> x >> w;
      x--;
      ll v = a[x];
      b[x / block][v]--;
      b[x / block][w]++;
      a[x] = w;
    } else { // consulta
      ll x, y, w;
      cin >> x >> y >> w;
      x--;
      y--;
      ll qtd{};
      ll c_l = x / block, c_r = y / block;

      if (c_l == c_r) {
        for (ll i = x; i <= y; ++i)
          if (a[i] == w)
            qtd++;
      } else {
        for (ll i = x, end = (c_l + 1) * block - 1; i <= end; ++i)
          if (a[i] == w)
            qtd++;
        for (ll i = c_l + 1; i <= c_r - 1; ++i)
          qtd += b[i][w];
        for (ll i = c_r * block; i <= y; ++i)
          if (a[i] == w)
            qtd++;
      }
      cout << (y - x + 1) - qtd << '\n';
    }
  }

  return 0;
}
