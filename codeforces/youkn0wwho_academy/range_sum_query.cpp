#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, q; cin >> n >> q;
  vll v(n), soma(n);
  ll x; cin >> x;
  v[0]=x; soma[0]=x;
  for (ll i=1; i<n; i++){
    cin >> x;
    v[i]=x;
    soma[i]=soma[i-1]+x;
  }

  while(q--){
    ll l,r; cin >> l >> r;
    l--; r--;
    if (l==0) cout << soma[r] << '\n';
    else cout << soma[r]-soma[l]+v[l] << '\n';
  }

  return 0;
}

