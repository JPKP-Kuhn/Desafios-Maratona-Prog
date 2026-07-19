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

const ll MAXN = 2 * 1e6 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;      // PD e inicialização de valor mínimo

ll t[MAXN], v[MAXN];

void build(ll id, ll l, ll r) {
  if (l == r)
    t[id] = v[l];
  else {
    ll m = (l + r) / 2;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);
    t[id] = t[2 * id] + t[2 * id + 1];
  }
}

ll query(ll id, ll l, ll r, ll ql, ll qr) {
  if (r < ql || l > qr)
    return 0;

  if (ql <= l && r <= qr)
    return t[id];

  ll mid = (l + r) / 2;
  return query(2 * id, l, mid, ql, qr) + query(2 * id + 1, mid + 1, r, ql, qr);
}

void update(ll id, ll l, ll r, ll p, ll x) {
  if (l == r)
    t[id] = x;
  else {
    ll m = (l + r) / 2;
    if (p <= m)
      update(2 * id, l, m, p, x);
    else
      update(2 * id + 1, m + 1, r, p, x);

    t[id] = t[2 * id] + t[2 * id + 1];
  }
}

int main() {
  _ ll n, q;
  cin >> n >> q;
  for (ll i{}; i < n; i++) {
    cin >> v[i];
  }

  build(1, 0, n - 1);

  while (q--) {
    ll o, a, b;
    cin >> o >> a >> b;

    if (o == 1) {
      update(1, 0, n - 1, a - 1, b);
    } else {
      cout << query(1, 0, n - 1, a - 1, b - 1) << '\n';
    }
  }

  return 0;
}
