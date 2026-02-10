#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll n; cin >> n;
    vll v(n);
    for (ll &x : v) cin >> x;
    for (ll i{}; i<n; i++){
      for (ll j=i; j<n; j++){
        vll sub(v.begin() + i, v.begin() + j+1);
        cout << *max_element(sub.begin(), sub.end()) << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}

