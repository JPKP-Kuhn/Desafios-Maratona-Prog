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

vll parent, ranq;

void make_set(ll v) {
  parent[v] = v;
  ranq[v] = 0;
}

ll find_set(ll v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void unions_sets(ll a, ll b) {
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

struct Edge {
  ll u, v, w;
  bool operator<(Edge const &other) { return w < other.w; }
};

ll n;
vector<Edge> edges;

int main() {
  _ ll m;
  cin >> n >> m;
  ll custo{};
  edges.resize(n + 1);
  parent.resize(n + 1);
  ranq.resize(n + 1);

  for (ll i = 1; i <= n; i++) {
    make_set(i);
  }

  while (m--) {
    ll u, v, c;
    cin >> u >> v >> c;
    Edge e;
    e.u = u;
    e.v = v;
    e.w = c;
    edges.push_back(e);
  }
  sort(all(edges));

  for (Edge e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
      custo += e.w;
      unions_sets(e.u, e.v);
    }
  }

  cout << custo << '\n';

  return 0;
}
