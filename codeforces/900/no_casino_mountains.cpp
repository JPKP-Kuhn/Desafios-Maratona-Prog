#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll n, k; cin >> n >> k;
    vll w(n); for (ll &x : w) cin >> x;

    ll c{};
    for (ll i=0; i<n; i++){
      if (w[i] == 0){
        ll soma{};
        for (ll j=i; j<n && j<=i+k-1; j++){
          soma+=w[j];
        }
        if (soma>0) continue;
        c++; i+=k;
      }
    }
    cout << c << '\n';
  }

  return 0;
}

