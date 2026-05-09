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
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

// M_PI para número PI
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

vector<vll> adj;
vb visited;
vb recstack;
bool f = false;

void isCyclicUtil(ll u) {
  if (recstack[u]) {
    f = true;
    return;
  }
  if (visited[u])
    return;

  visited[u] = true;
  recstack[u] = true;

  for (ll v : adj[u]) {
    isCyclicUtil(v);
    if (f)
      return;
  }

  recstack[u] = false;
}

void dfs() {
  recstack.assign(adj.size(), false);
  visited.assign(adj.size(), false);
  for (ll i{1}; i < adj.size(); i++) {
    if (!visited[i] && !f) {
      isCyclicUtil(i);
    }
  }
}

int main() {
  _ ll t;
  cin >> t;
  while (t--) {
    f = false;
    adj.clear();
    visited.clear();
    recstack.clear();
    ll n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    recstack.assign(n + 1, false);
    visited.assign(n + 1, false);
    while (m--) {
      ll a, b;
      cin >> a >> b;
      adj[a].push_back(b);
    }
    dfs();
    cout << (f ? "SIM" : "NAO") << '\n';
  }

  return 0;
}
