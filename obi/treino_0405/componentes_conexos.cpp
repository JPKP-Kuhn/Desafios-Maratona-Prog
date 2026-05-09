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

vector<vll> adj;
vb visited;
vll comp;

ll letnum(char l) {
  ll i = 0;
  for (char le = 'a'; le <= 'z'; le++) {
    if (le == l) {
      return i;
    }
    i++;
  }
  return -1;
}

void dfs(ll v) {
  visited[v] = true;
  comp.push_back(v);
  for (ll u : adj[v]) {
    if (!visited[u])
      dfs(u);
  }
}

ll ncomp;
void find_comp() {
  visited.assign(adj.size(), false);
  for (ll v = 0; v < adj.size(); v++) {
    if (!visited[v]) {
      comp.clear();
      ncomp++;
      dfs(v);

      sort(comp.begin(), comp.end());
      for (ll u : comp) {
        cout << char(u + 'a') << ",";
      }
      cout << '\n';
    }
  }
}

int main() {
  _ ll n;
  cin >> n;
  for (ll caso = 1; caso <= n; caso++) {
    ll v, e;
    cin >> v >> e;
    adj.clear();
    adj.resize(v);
    visited.clear();
    visited.assign(v, false);
    ncomp = 0;

    while (e--) {
      char l, r;
      cin >> l >> r;
      ll la = letnum(l), lb = letnum(r);
      adj[la].push_back(lb);
      adj[lb].push_back(la);
    }

    cout << "Case #" << caso << ":\n";
    find_comp();
    cout << ncomp << " connected components\n\n";
  }

  return 0;
}
