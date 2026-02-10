#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m; cin >> n >> m;
  vll a(n);
  for (ll &x : a) cin >> x;

  ll idx{};
  ll c{};
  for (ll i{}; i<m; i++){
    ll x; cin >> x;

    for (ll j=idx; j<n; j++){
      if (a[j] == x){
        idx=j+1; c++;
        break;
      }
    }
  }

  cout << (c < m ? "NO" : "YES") << '\n';
  return 0;
}

