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
  vector<vpll> adj(n + 1);
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }

  priority_queue<pl, vpll, greater<pl>> q;
  q.push({0, 1});

  vll dist(n + 1, INF);
  dist[1] = 0;
  while (!q.empty()) {
    auto [d, v] = q.top();
    q.pop();
    if (d != dist[v])
      continue;
    for (auto &[w, u] : adj[v]) {
      if (dist[v] + w < dist[u]) {
        dist[u] = dist[v] + w;
        q.push({dist[u], u});
      }
    }
  }
  cout << dist[n] << '\n';

  return 0;
}
