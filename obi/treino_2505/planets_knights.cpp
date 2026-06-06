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

vector<bool> visited;
vector<vll> adj, adj_trans;
vll order, kingdom;

void dfsOrder(ll v) {
  visited[v] = true;
  for (ll u : adj[v]) {
    if (!visited[u]) {
      dfsOrder(u);
    }
  }
  order.push_back(v);
}

void dfs2(ll v, ll id) {
  visited[v] = true;
  kingdom[v] = id;

  for (ll u : adj_trans[v]) {
    if (!visited[u]) {
      dfs2(u, id);
    }
  }
}

int main() {
  _ ll n, m;
  cin >> n >> m;
  adj.assign(n + 1, {});
  adj_trans.assign(n + 1, {});
  visited.assign(n + 1, false);
  while (m--) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj_trans[b].push_back(a);
  }

  for (ll i{1}; i <= n; i++) {
    if (!visited[i])
      dfsOrder(i);
  }

  fill(all(visited), false);
  kingdom.assign(n + 1, 0);

  ll k{};
  for (ll i = order.size() - 1; i >= 0; i--) {
    ll v = order[i];
    if (!visited[v]) {
      k++;
      dfs2(v, k);
    }
  }

  cout << k << '\n';
  for (ll i = 1; i <= n; i++) {
    cout << kingdom[i] << ' ';
  }
  cout << '\n';

  return 0;
}
