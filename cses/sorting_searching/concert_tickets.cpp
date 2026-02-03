#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m; cin >> n >> m;
  multiset<ll> tic;
  for (ll i{}; i<n; ++i){
    ll x; cin >> x;
    tic.insert(x);
  }

  for (ll i{}; i<m; ++i){
    ll x; cin >> x;
    auto it = tic.upper_bound(x);
    if (it == tic.begin()) cout << -1 << '\n';
    else {
      cout << *(--it) << '\n';
      tic.erase(it);
    }
  }


  return 0;
}

