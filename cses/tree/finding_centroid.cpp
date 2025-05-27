#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;

const ll maxn = 200010;
ll n;
vector<ll> tree[maxn];
ll subtree_size[maxn];

ll get_subtree_size(ll node, ll parent = -1) {
  ll &res = subtree_size[node];
  res = 1;
  for (ll i : tree[node]) {
    if (i == parent) { continue;}
    res += get_subtree_size(i, node);
  }
  return res;
}

ll get_centroid(ll node, ll parent = -1) {
  for (ll i : tree[node]) {
    if (i == parent) {continue;}

    if (subtree_size[i] * 2 > n) {return get_centroid(i, node);}

  }
  return node;
}



int main() {
  scanf("%lld", &n);
  for (ll i=0;i<n-1;i++){

    ll a, b;
    scanf("%lld %lld", &a, &b);
    a--; b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  get_subtree_size(0);
  printf("%lld\n", get_centroid(0)+1);
  return 0;
}

