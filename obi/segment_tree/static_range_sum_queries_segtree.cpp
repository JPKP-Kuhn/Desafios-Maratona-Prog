#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

const ll MAXN = 2 * 1e6 + 10; // Range seguro para vetores e arrays

ll t[MAXN];
ll a[MAXN];

void build(ll v, ll l, ll r) {
  if (l == r) {
    t[v] = a[l];
    return;
  }
  ll mid = (l + r) / 2;

  build(2 * v, l, mid);
  build(2 * v + 1, mid + 1, r);

  t[v] = t[2 * v] + t[2 * v + 1];
}

ll query(ll v, ll l, ll r, ll ql, ll qr) {
  if (r < ql || l > qr)
    return 0;

  if (ql <= l && r <= qr) {
    return t[v];
  }

  ll mid = (l + r) / 2;
  return query(2 * v, l, mid, ql, qr) + query(2 * v + 1, mid + 1, r, ql, qr);
}

int main() {
  _ ll n, q;
  cin >> n >> q;
  for (ll i{}; i < n; i++) {
    ll x;
    cin >> x;
    a[i] = x;
  }
  build(1, 0, n - 1);

  while (q--) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    cout << query(1, 0, n - 1, a, b) << '\n';
  }

  return 0;
}
