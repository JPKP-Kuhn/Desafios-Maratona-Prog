#include <bits/stdc++.h>
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

const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

void bfs(vector<vll> &adj, ll i, vb &vis) {
  queue<ll> q;
  q.push(i);
  vis[i] = true;
  while (!q.empty()) {
    ll v = q.front();
    q.pop();

    for (ll u : adj[v]) {
      if (!vis[u]) {
        vis[u] = true;
        q.push(u);
      }
    }
  }
}

int main() {
  _ ll n, m;
  cin >> n >> m;
  vector<vll> adj(n + 1);
  vb vis(n + 1);
  vll representantes;
  while (m--) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (ll i = 1; i <= n; i++) {
    if (!vis[i]) {
      representantes.push_back(i);
      bfs(adj, i, vis);
    }
  }

  ll c = representantes.size();
  ll k = c - 1;
  cout << k << '\n';
  for (ll i{}; i < k; i++) {
    cout << representantes[i] << ' ' << representantes[i + 1] << '\n';
  }
  return 0;
}
