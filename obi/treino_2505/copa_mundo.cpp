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

const ll MAXN = 1e6 + 10; // Range seguro para vetores e arrays

struct Edge {
  ll u, v, w;
  bool rodovia;
  bool operator<(Edge const &other) {
    if (rodovia != other.rodovia)
      return rodovia < other.rodovia;
    return w < other.w;
  }
};

vector<Edge> adj;
vll parent, ranq;

ll find_set(ll v) {
  if (parent[v] == v)
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
  _ ll n, f, r;
  cin >> n >> f >> r;

  parent.resize(f + r + 1);
  ranq.resize(f + r + 1);

  for (ll i{1}; i <= f + r; i++) {
    parent[i] = i;
    ranq[i] = 0;
  }

  while (f--) {
    ll a, b, c;
    cin >> a >> b >> c;

    Edge e;
    e.v = a;
    e.u = b;
    e.w = c;
    e.rodovia = false;
    adj.push_back(e);
  }

  while (r--) {
    ll a, b, c;
    cin >> a >> b >> c;

    Edge e;
    e.v = a;
    e.u = b;
    e.w = c;
    e.rodovia = true;
    adj.push_back(e);
  }
  sort(all(adj));
  ll custo{};

  for (Edge e : adj) {
    if (find_set(e.u) != find_set(e.v)) {
      custo += e.w;
      union_set(e.u, e.v);
    }
  }

  cout << custo << '\n';

  return 0;
}
