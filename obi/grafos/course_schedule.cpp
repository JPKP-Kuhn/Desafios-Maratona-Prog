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

ll n;
vector<vll> adj;
vll cor;
vll ans;
bool f = false;

void dfs(ll v) {
  cor[v] = 1;
  for (ll u : adj[v]) {
    if (cor[u] == 0)
      dfs(u);
    else if (cor[u] == 1)
      f = true;
  }
  ans.pb(v);
  cor[v] = 2;
}

int main() {
  _ ll m;
  cin >> n >> m;
  adj.assign(n + 1, {});
  cor.assign(n + 1, 0);
  while (m--) {
    ll a, b;
    cin >> a >> b;
    adj[a].pb(b);
  }

  for (ll i = 1; i <= n; i++) {
    if (cor[i] == 0) {
      dfs(i);
    }
  }
  if (f) {
    cout << "IMPOSSIBLE\n";
  } else {
    reverse(all(ans));
    for (ll i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }

  return 0;
}
