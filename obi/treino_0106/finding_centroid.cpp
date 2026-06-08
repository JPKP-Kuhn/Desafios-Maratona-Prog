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

vector<vll> adj;
vll subtree_size;
ll n;

ll get_subtree_size(ll node, ll parent = -1) {
  ll &res = subtree_size[node];
  res = 1;

  for (ll i : adj[node]) {
    if (i == parent)
      continue;
    res += get_subtree_size(i, node);
  }
  return res;
}

ll get_centroid(ll node, ll parent = -1) {
  for (ll i : adj[node]) {
    if (i == parent)
      continue;
    if (subtree_size[i] * 2 > n) {
      return get_centroid(i, node);
    }
  }
  return node;
}
int main() {
  _ cin >> n;
  adj.resize(n + 1);
  subtree_size.resize(n + 1);
  for (ll i{}; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  get_subtree_size(1);
  cout << get_centroid(1) << '\n';

  return 0;
}
