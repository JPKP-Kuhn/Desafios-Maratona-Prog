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
vll color;

bool dfs(ll v, ll c) {
  color[v] = c;
  for (ll u : adj[v]) {
    if (color[u] == 0) {
      if (!dfs(u, 3 - c))
        return false;
    } else if (color[u] == c)
      return false;
  }
  return true;
}

int main() {
  _ cin >> n >> m;
  adj.resize(n + 1);
  color.assign(n + 1, 0);

  while (m--) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (ll i = 1; i <= n; i++) {
    if (color[i] == 0) {
      if (!dfs(i, 1)) {
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
  }

  for (ll i = 1; i <= n; i++) {
    cout << color[i] << ' ';
  }
  cout << '\n';

  return 0;
}
