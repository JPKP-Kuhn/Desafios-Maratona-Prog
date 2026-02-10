#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m; cin >> n >> m;
  map<ll, ll> d;
  for (ll i=1; i<=m; i++){
    d[i]=0;
  }
  for (ll i{}; i<n; i++){
    ll x; cin >> x;
    d[x]++;
  }

  for (auto &[k, v] : d){
    cout << v << '\n';
  }

  return 0;
}

