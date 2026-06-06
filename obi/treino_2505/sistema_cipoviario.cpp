#include <algorithm>
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

const double PI = 3.14159265358979323846;
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

struct edge {
  ll v, u, w;
  bool operator<(const edge &other) { return w < other.w; }
};

vll parent, ranq;

ll find_set(ll v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_set(ll a, ll b) {
  a = find_set(a);
  b = find_set(b);

  if (a != b) {
    if (ranq[a] < ranq[b])
      swap(a, b);
    parent[b] = a;
    if (ranq[a] == ranq[b])
      ranq[a]++;
  }
}

int main() {
  _ ll n, m;
  ll caso{};
  while (cin >> n >> m) {
    parent.resize(n + 1);
    ranq.resize(n + 1);
    vector<edge> adj;
    for (ll i{1}; i <= n; i++) {
      parent[i] = i;
      ranq[i] = 0;
    }

    while (m--) {
      ll a, b, c;
      cin >> a >> b >> c;
      edge e = {a, b, c};
      adj.push_back(e);
    }
    sort(all(adj));
    ll custo{};

    for (edge e : adj) {
      if (find_set(e.u) != find_set(e.v)) {
        custo += e.w;
        union_set(e.u, e.v);
      }
    }
    cout << "Instancia " << ++caso << '\n';
    cout << custo << '\n';
    cout << '\n';
  }

  return 0;
}
