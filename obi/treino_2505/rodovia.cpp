#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;

vector<vll> adj, adj_trans;
vb visited;

void dfs(ll v, vector<vll> &adj) {
  visited[v] = true;

  for (ll u : adj[v]) {
    if (!visited[u])
      dfs(u, adj);
  }
}

int main() {
  _ ll n;
  cin >> n;

  adj.assign(n + 1, {});
  adj_trans.assign(n + 1, {});
  visited.assign(n + 1, false);

  for (ll i{}; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);

    adj_trans[b].push_back(a);
  }

  dfs(1, adj);

  for (ll i{1}; i <= n; i++) {
    if (!visited[i]) {
      cout << "N\n";
      return 0;
    }
  }

  visited.assign(n + 1, false);

  dfs(1, adj_trans);

  for (ll i{1}; i <= n; i++) {
    if (!visited[i]) {
      cout << "N\n";
      return 0;
    }
  }
  cout << "S\n";

  return 0;
}
