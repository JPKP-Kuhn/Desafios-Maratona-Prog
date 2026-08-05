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

int main() {
  _ ll n, m;
  cin >> n >> m;
  vector<vll> adj(n + 1);
  vll pai(n + 1);
  vb vis(n + 1);
  while (m--) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<ll> q;
  q.push(1);
  pai[1] = -1;
  vis[1] = true;

  bool f = false;
  vll route;
  while (!q.empty()) {
    ll v = q.front();
    q.pop();

    if (v == n) {
      f = true;
      route.push_back(v);
      while (v != 1) {
        v = pai[v];
        route.push_back(v);
      }
      break;
    }

    for (ll u : adj[v]) {
      if (!vis[u]) {
        q.push(u);
        pai[u] = v;
        vis[u] = true;
      }
    }
  }

  if (!f) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << route.size() << '\n';
    reverse(all(route));
    for (ll x : route) {
      cout << x << ' ';
    }
    cout << '\n';
  }

  return 0;
}
