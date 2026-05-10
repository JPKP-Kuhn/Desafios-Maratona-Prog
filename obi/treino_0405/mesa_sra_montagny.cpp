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
bool f = true;
vll colors;

void dfs(ll v, ll cor) {
  colors[v] = cor;
  for (ll u : adj[v]) {
    if (colors[u] == -1) {
      dfs(u, 1 - cor);
    } else if (colors[u] == cor) {
      f = false;
      return;
    }
  }
}

int main() {
  _ ll n, m;
  // grafos bipartidos
  ll caso{};
  while (cin >> n >> m) {
    adj.assign(n + 1, {});
    colors.assign(n + 1, -1);
    f = true;

    while (m--) {
      ll a, b;
      cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
    }
    for (ll i = 1; i <= n; i++) {
      if (colors[i] == -1) {
        dfs(i, 0);
      }
    }

    cout << "Instancia " << ++caso << '\n';
    cout << (f ? "sim\n" : "nao\n");
    cout << '\n';
  }

  return 0;
}
