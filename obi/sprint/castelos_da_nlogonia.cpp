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

ll n, m;
vector<vll> adj;
vll cores, pai;

bool dfs(ll o, ll p, ll d) {
  pai[o] = p;

  if (o == d)
    return true;

  for (ll u : adj[o]) {
    if (u == p)
      continue;

    if (dfs(u, o, d))
      return true;
  }
  return false;
}

int main() {
  _ cin >> n >> m;
  adj.assign(n + 1, {});
  cores.assign(n + 1, 0);
  pai.assign(n + 1, 0);

  for (ll i{}; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  while (m--) {
    ll p, q, c;
    cin >> p >> q >> c;
    dfs(p, -1, q);

    for (ll v = q; v != -1; v = pai[v]) {
      cores[v] = c;
    }
  }

  for (ll i{1}; i <= n; i++) {
    cout << cores[i] << ' ';
  }
  cout << '\n';

  return 0;
}
