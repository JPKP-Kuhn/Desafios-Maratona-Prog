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
const ll MOD = 1e9 + 7;       // aritmética modular, números muito grandes
const double EPS = 1e-9;      // Valor para comparar double

ll t[MAXN];
ll a[MAXN];

ll combine(ll a, ll b) {
  if (a < b)
    return a;
  else if (b < a)
    return b;

  return a;
}

ll get_min(ll v, ll tl, ll tr, ll l, ll r) {
  if (r < tl || l > tr)
    return INF;

  if (l == tl && r == tr)
    return t[v];

  ll tm = (tl + tr) / 2;
  return combine(get_min(v * 2, tl, tm, l, min(r, tm)),
                 get_min(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void build(ll v, ll tl, ll tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    ll tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }
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
    a--;
    b--;
    cout << get_min(1, 0, n - 1, a, b) << '\n';
  }

  return 0;
}
