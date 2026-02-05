#include <bits/stdc++.h>
#include <set>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m; cin >> n >> m;
  set<ll> f;
  for (ll i{}; i<m; i++){
    ll x; cin >> x;
    f.insert(x);
  }
  cout << n-f.size() << '\n';

  return 0;
}

