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
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

// M_PI para número PI
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

ll n;
vector<vll> adj;
ll c;
vb visited;

void dfs(ll inicio) {
  visited[inicio] = true;
  for (ll i : adj[inicio]) {
    if (!visited[i]) {
      dfs(i);
      c++;
    }
  }
}

int main() {
  _ ll t;
  cin >> t;
  while (t--) {
    cin >> n;
    ll v, a;
    cin >> v >> a;
    adj.clear();
    adj.resize(v + 1);
    visited.assign(v + 1, false);
    c = 0;
    while (a--) {
      ll x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    dfs(n);
    cout << c * 2 << '\n';
  }

  return 0;
}
