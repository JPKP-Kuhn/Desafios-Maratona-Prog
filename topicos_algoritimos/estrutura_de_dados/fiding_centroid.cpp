#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

vll tree[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;


  for (ll i=0; i<n-1; i++){
    ll u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }


  return 0;
}

