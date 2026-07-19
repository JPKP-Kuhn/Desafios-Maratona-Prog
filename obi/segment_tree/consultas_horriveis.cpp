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

const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

ll t[4 * MAXN], v[MAXN], inter[4 * MAXN];

void push(ll id, ll ql, ll qr) {
  if (inter[id] == 0)
    return;

  ll m = (ql + qr) / 2;

  t[id * 2] += (m - ql + 1) * inter[id];
  inter[id * 2] += inter[id];

  t[id * 2 + 1] += (qr - m) * inter[id];
  inter[id * 2 + 1] += inter[id];

  inter[id] = 0;
}

void update_intervalo(ll id, ll l, ll r, ll ql, ll qr, ll x) {
  if (qr < l || r < ql)
    return;

  if (ql <= l && r <= qr) {
    t[id] += 1LL * (r - l + 1) * x;
    inter[id] += x;
    return;
  }

  push(id, l, r);
  ll m = (l + r) / 2;

  update_intervalo(2 * id, l, m, ql, min(qr, m), x);
  update_intervalo(2 * id + 1, m + 1, r, max(ql, m + 1), qr, x);

  t[id] = t[id * 2] + t[id * 2 + 1];
}

void build(ll id, ll l, ll r) {
  if (l == r) {
    t[id] = v[l];
    return;
  } else {
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

  push(id, l, r);

  ll m = (l + r) / 2;
  return query(2 * id, l, m, ql, min(qr, m)) +
         query(2 * id + 1, m + 1, r, max(ql, m + 1), qr);
}

int main() {
  _ ll teste;
  cin >> teste;
  while (teste--) {
    ll n, q;
    cin >> n >> q;

    memset(inter, 0, sizeof(inter));
    memset(t, 0, sizeof(t));

    while (q--) {
      ll o;
      cin >> o;
      if (o == 0) {
        ll p, q, v;
        cin >> p >> q >> v;
        update_intervalo(1, 0, n - 1, p - 1, q - 1, v);
      } else {
        ll p, q;
        cin >> p >> q;
        cout << query(1, 0, n - 1, p - 1, q - 1) << '\n';
      }
    }
  }
  return 0;
}
