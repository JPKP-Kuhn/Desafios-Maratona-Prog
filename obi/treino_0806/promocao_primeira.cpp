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

const ll MAXN = 1e6;

vector<vpll> adj;
ll dp[MAXN][2];
ll cont = 1;

void dfs(ll v, ll p) {
  dp[v][0] = dp[v][1] = 1;

  ll best0 = 1;
  ll best1 = 1;

  for (auto &[u, bus] : adj[v]) {
    if (u == p)
      continue;

    dfs(u, v);

    ll cand = 1 + dp[u][1 - bus];

    if (bus == 0) {
      best0 = max(best0, cand);
      dp[v][0] = max(dp[v][0], cand);
    } else {
      best1 = max(best1, cand);
      dp[v][1] = max(dp[v][1], cand);
    }

    cont = max(cont, best0);
    cont = max(cont, best1);

    cont = max(cont, best0 + best1 - 1);
  }
}

int main() {
  _ ll n;
  cin >> n;
  adj.resize(n + 1);
  for (ll i{}; i < n - 1; i++) {
    ll a, b, e;
    cin >> a >> b >> e;
    adj[a].push_back({b, e});
    adj[b].push_back({a, e});
  }

  dfs(1, 0);

  cout << cont << '\n';

  return 0;
}
