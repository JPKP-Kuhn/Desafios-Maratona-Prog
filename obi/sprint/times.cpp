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

const double PI = 3.14159265358979323846;
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

ll n;
vector<vll> adj;
vll color;

bool dfs(ll v, ll c) {
  color[v] = c;

  for (ll u : adj[v]) {
    if (color[u] == 0) {
      if (!dfs(u, 3 - c))
        return false;
    } else if (color[u] == c)
      return false;
  }
  return true;
}

int main() {
  _ cin >> n;
  adj.resize(n + 1);
  color.assign(n + 1, 0);
  for (ll i{1}; i <= n; i++) {
    ll m;
    cin >> m;
    while (m--) {
      ll x;
      cin >> x;
      adj[i].push_back(x);
    }
  }
  dfs(1, 1);

  vll a, b;
  for (ll i = 1; i <= n; i++) {
    if (color[i] == 1)
      a.push_back(i);
    else if (color[i] == 2)
      b.push_back(i);
  }

  for (ll x : a)
    cout << x << ' ';

  cout << '\n';
  for (ll x : b)
    cout << x << ' ';
  cout << '\n';
  return 0;
}
