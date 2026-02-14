#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  for (ll test=1; test<=t; test++){
    ll n; cin >> n;
    ll h{}, s{};
    ll f; cin >> f;
    for (ll i{}; i<n-1; i++){
      ll x; cin >> x;
      if (x>f){
        h++; f=x;
      } else if (x<f){
        s++; f=x;
      }
    }

    cout << "Case " << test << ": " << h << ' ' << s << '\n';
  }

  return 0;
}

