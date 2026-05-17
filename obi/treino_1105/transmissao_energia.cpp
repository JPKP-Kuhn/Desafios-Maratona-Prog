#include <bits/stdc++.h>
#include <variant>
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

// M_PI para número PI
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

struct point {
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator<(point other) const {
    if (fabs(x - other.x) > EPS)
      return x < other.x;
    return y < other.y;
  };
};

vector<vll> adj;
vb visited;
vll nos;
void dfs(ll v) {
  visited[v] = true;
  nos.pb(v);
  for (ll u : adj[v]) {
    if (!visited[u])
      dfs(u);
  }
}

int main() {
  _ ll e, l;
  ll teste{};
  while (cin >> e >> l && e && l) {

    adj.assign(e + 1, {});
    visited.assign(e + 1, false);
    nos.clear();
    nos.resize(0);

    while (l--) {
      ll x, y;
      cin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
    }

    dfs(1);
    cout << "Teste " << ++teste << '\n';
    cout << (nos.size() == e ? "normal\n" : "falha\n");
    cout << '\n';
  }

  return 0;
}
