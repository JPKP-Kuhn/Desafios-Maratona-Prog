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

ll n, m;
vector<vll> adj;
vll parent;
ll cycle_start, cycle_end;
vb visited;

bool dfs(int v, int par) { // passing vertex and its parent vertex
  visited[v] = true;
  for (int u : adj[v]) {
    if (u == par)
      continue; // skipping edge to parent vertex
    if (visited[u]) {
      cycle_end = v;
      cycle_start = u;
      return true;
    }
    parent[u] = v;
    if (dfs(u, parent[u]))
      return true;
  }
  return false;
}

void find_cycle() {
  visited.assign(n + 1, false);
  parent.assign(n + 1, -1);
  cycle_start = -1;

  for (int v = 1; v <= n; v++) {
    if (!visited[v] && dfs(v, -1))
      break;
  }

  if (cycle_start == -1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v])
      cycle.push_back(v);
    cycle.push_back(cycle_start);

    cout << cycle.size() << '\n';
    for (int v : cycle)
      cout << v << " ";
    cout << endl;
  }
}

int main() {
  _ cin >> n >> m;
  adj.assign(n + 1, {});

  while (m--) {
    ll a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  find_cycle();

  return 0;
}
