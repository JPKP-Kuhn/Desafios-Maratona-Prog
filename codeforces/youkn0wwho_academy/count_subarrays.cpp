#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

bool cresc(vll &v){
  ll ant=v[0];
  ll len=v.size();
  for (ll i=1; i<len; i++){
    if (v[i] < ant) return false;
    ant = v[i];
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll n; cin >> n;
    vll v(n);
    for (ll &x : v) cin >> x;

    ll c{};
    for (ll i{}; i<n; i++){
      for (ll j=i; j<n; j++){
        vll sub(v.begin()+i, v.begin()+j+1);
        if (cresc(sub)) c++;
      }
    }
    cout << c << '\n';
  }

  return 0;
}

