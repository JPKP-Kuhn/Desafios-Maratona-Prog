#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll l; cin >> l;
    vll v(l);
    for (ll &x : v) cin >> x;
    ll c{};
    bool s{};

    for (ll i{}; i<l-1; i++){
      s=false;
      for (ll j{}; j<l-1; j++){
        if (v[j] > v[j+1]){
          swap(v[j], v[j+1]);
          s = true; c++;
        }
      }
      if (!s) break;
    }

    cout << "Optimal train swapping takes " << c << " swaps.\n";
  }

  return 0;
}

