#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  set<ll> a;
  for (ll i=0; i<n; i++){
    ll x; cin >> x;
    a.insert(x);
  }
  cout << a.size() << '\n';

  return 0;
}

