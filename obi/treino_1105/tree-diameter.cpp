#include <bits/stdc++.h>
#include <climits>
#include <queue>
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

vector<vll> adj;
vb visited;
vll dist;
void dfs(ll v, ll p) {
  for (ll u : adj[v]) {
    if (u == p)
      continue;

    dist[u] = dist[v] + 1;
    dfs(u, v);
  }
}

int main() {
  _ ll n;
  cin >> n;
  adj.assign(n + 1, {});
  dist.assign(n + 1, 0);
  visited.assign(n + 1, false);
  for (ll i{}; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, -1);
  ll A = 1;
  for (ll i = 1; i <= n; i++) {
    if (dist[i] > dist[A])
      A = i;
  }

  dist.assign(n + 1, 0);
  dfs(A, -1);
  ll diametro{};

  for (ll i = 1; i <= n; i++) {
    diametro = max(diametro, dist[i]);
  }
  cout << diametro << '\n';

  return 0;
}
