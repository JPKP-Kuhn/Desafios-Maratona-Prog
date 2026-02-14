#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll mile(ll x){
  ll i = x/30; i++;
  return 10*i;
}

ll juice(ll x){
  ll i = x/60; i++;
  return 15*i;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  for (ll caso=1; caso<=t; caso++){
    ll n; cin >> n;
    ll m{},j{};
    while(n--){
      ll x; cin >> x;
      m+=mile(x); j+=juice(x);
    }
    cout << "Case " << caso << ": ";
    if (m==j) cout << "Mile Juice " << m << '\n';
    else cout << (m<j ? "Mile " : "Juice ") << min(m,j) << '\n';
  }

  return 0;
}

