#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T; cin >> T;
  while(T--){
    ll n; cin >> n;
    ll r = 100000000000;
    vll v(n);
    for (ll &x : v) cin >> x;
    for (ll i{}; i<n; i++){
      for (ll j=i+1; j<n; j++){
        r = min(r, v[i]+v[j]+(j+1)-(i+1));
      }
    }
    cout << r << '\n';
  }

  return 0;
}

