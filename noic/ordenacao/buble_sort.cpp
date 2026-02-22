#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  vll v(n);
  for (ll &x : v) cin >> x;

  for (ll i=0; i<n; i++){
    bool s=false;
    for (ll j=0; j<n-1; j++){
      if (v[j] > v[j+1]){
        swap(v[j], v[j+1]);
        s=true;
      }
    }
    if (!s) break;
  }

  for (ll i : v) cout << i << ' ';
  cout << '\n';

  return 0;
}

