#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t{};
  ll n;
  while(cin >> n){
    ll m=1e10, ma=-1e10;
    ll x;
    for (ll i{}; i<n; i++){
      cin >> x;
      m=min(m, x);
      ma=max(ma, x);
    }
    ll r = ma-m;

    cout << "Case " << ++t << ": " << m << ' ' << ma << ' ' << r << '\n';
  }

  return 0;
}

