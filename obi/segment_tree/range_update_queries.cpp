#include <bits/stdc++.h>
#include <cstring>
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

const ll MAXN = 2 * 1e6 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;      // PD e inicialização de valor mínimo

ll t[MAXN], v[MAXN];

void update_intervalo(ll id, ll l, ll r, ll ql, ll qr, ll x) {
  if (qr < l || r < ql)
    return;

  if (ql <= l && r <= qr) {
    t[id] += x;
    return;
  }

  ll m = (r + l) / 2;
  update_intervalo(2 * id, l, m, ql, qr, x);
  update_intervalo(2 * id + 1, m + 1, r, ql, qr, x);
}

ll query_ponto(ll id, ll l, ll r, ll p) {
  if (l == r) {
    return t[id] + v[l];
  }
  ll m = (l + r) / 2;
  if (p <= m) {
    return t[id] + query_ponto(2 * id, l, m, p);
  } else {
    return t[id] + query_ponto(2 * id + 1, m + 1, r, p);
  }
}

int main() {
  _ ll n, q;
  cin >> n >> q;
  for (ll i{}; i < n; i++) {
    cin >> v[i];
  }
  memset(t, 0, sizeof(t));
  while (q--) {
    ll o;
    cin >> o;
    if (o == 1) {
      ll a, b, u;
      cin >> a >> b >> u;
      update_intervalo(1, 0, n - 1, a - 1, b - 1, u);
    } else {
      ll k;
      cin >> k;
      cout << query_ponto(1, 0, n - 1, k - 1) << '\n';
    }
  }

  return 0;
}
