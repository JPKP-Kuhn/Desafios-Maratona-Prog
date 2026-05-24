#include <bits/stdc++.h>
#include <queue>
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

// M_PI para número PI
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

int main() {
  _ ll n, m;
  cin >> n >> m;

  vector<vll> adj(n);
  vll grau(n, 0);

  for (ll i{}; i < m; i++) {
    ll a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    grau[b]++;
  }

  priority_queue<ll, vll, greater<ll>> pq;

  for (ll i{}; i < n; i++) {
    if (grau[i] == 0)
      pq.push(i);
  }

  vll ans;

  while (!pq.empty()) {
    ll v = pq.top();
    pq.pop();

    ans.push_back(v);

    for (ll u : adj[v]) {
      grau[u]--;

      if (grau[u] == 0)
        pq.push(u);
    }
  }

  if ((ll)ans.size() != n) {
    cout << "*\n";
    return 0;
  }

  for (ll x : ans) {
    cout << x << '\n';
  }
  return 0;
}
