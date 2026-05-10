#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define pb push_back
#define all(x) x.begin(), x.end()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;

vector<vll> adj;
vb visited;
vll cit;
ll c, e, l, p;

int main() {
  _ ll teste{};
  while (cin >> c >> e >> l >> p) {
    if (c == 0 && e == 0 && l == 0 && p == 0)
      break;
    adj.assign(c + 1, {});
    visited.assign(c + 1, false);
    cit.clear();
    while (e--) {
      ll a, b;
      cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
    }
    vll dist(c + 1, -1);
    queue<ll> fila;
    fila.push(l);
    dist[l] = 0;
    while (!fila.empty()) {
      ll v = fila.front();
      fila.pop();

      for (ll u : adj[v]) {
        if (dist[u] == -1) {
          dist[u] = dist[v] + 1;

          if (dist[u] <= p)
            fila.push(u);
        }
      }
    }
    for (ll i = 1; i <= c; i++) {
      if (i != l && dist[i] != -1 && dist[i] <= p)
        cit.pb(i);
    }

    cout << "Teste " << ++teste << '\n';
    sort(all(cit));
    for (ll i : cit) {
      cout << i << ' ';
    }
    cout << "\n\n";
  }

  return 0;
}
