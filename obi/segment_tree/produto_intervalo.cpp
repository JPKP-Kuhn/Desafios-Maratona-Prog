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

const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo

ll t[4 * MAXN], v[MAXN];

void build(ll id, ll l, ll r) {
  if (l == r) {
    if (v[l] == 0)
      t[id] = 0;
    else
      t[id] = (v[l] > 0 ? 1 : -1);
    return;
  }
  ll m = (l + r) / 2;
  build(2 * id, l, m);
  build(2 * id + 1, m + 1, r);
  t[id] = t[2 * id] * t[2 * id + 1];
}

void update(ll id, ll l, ll r, ll p, ll x) {
  if (l == r) {
    if (x == 0)
      t[id] = 0;
    else
      t[id] = (x > 0 ? 1 : -1);
  } else {
    ll m = (l + r) / 2;
    if (p <= m) {
      update(2 * id, l, m, p, x);
    } else {
      update(2 * id + 1, m + 1, r, p, x);
    }
    ll prod = t[2 * id] * t[2 * id + 1];
    if (prod == 0)
      t[id] = 0;
    else
      t[id] = (prod > 0 ? 1 : -1);
  }
}

ll query(ll id, ll l, ll r, ll ql, ll qr) {
  if (r < ql || l > qr)
    return 1;

  if (ql <= l && r <= qr)
    return t[id];

  ll m = (l + r) / 2;
  return query(2 * id, l, m, ql, qr) * query(2 * id + 1, m + 1, r, ql, qr);
}

int main() {
  _ ll n, k;
  while (cin >> n >> k) {
    for (ll i{}; i < n; i++) {
      cin >> v[i];
    }
    build(1, 0, n - 1);

    while (k--) {
      char o;
      ll a, b;
      cin >> o >> a >> b;
      if (o == 'C') {
        update(1, 0, n - 1, a - 1, b);
      } else {
        ll value = query(1, 0, n - 1, a - 1, b - 1);
        if (value == 0)
          cout << 0;
        else
          cout << (value > 0 ? '+' : '-');
      }
    }
    cout << '\n';
  }
  return 0;
}
