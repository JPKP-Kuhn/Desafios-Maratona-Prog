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
    vll v(n); for(ll &x : v) cin >> x;
    vll nova = v;
    sort(v.rbegin(), v.rend());
    ll r{};
    for (ll i{}; i<n; i++){
      if (v[i]==nova[i]) r++;
    }
    cout << r << '\n';
  }

  return 0;
}

