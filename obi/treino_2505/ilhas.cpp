#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo

int main() {
  _ ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> adj(n + 1);
  while (m--) {
    ll ui, vi, pi;
    cin >> ui >> vi >> pi;

    adj[ui].push_back({pi, vi});
    adj[vi].push_back({pi, ui});
  }
  ll ser;
  cin >> ser;

  ll menor = 100000;
  ll maior = 0;

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
      fila;
  vll dist(n + 1, INF);

  dist[ser] = 0;
  fila.push({0, ser});

  while (!fila.empty()) {
    ll d = fila.top().first;
    ll v = fila.top().second;
    fila.pop();

    if (d > dist[v])
      continue;

    if (v != ser) {
      maior = max(maior, d);
      menor = min(menor, d);
    }

    for (pl p : adj[v]) {
      ll w = p.first;
      ll u = p.second;

      if (dist[v] + w < dist[u]) {
        dist[u] = dist[v] + w;
        fila.push({dist[u], u});
      }
    }
  }

  cout << maior - menor << '\n';

  return 0;
}
