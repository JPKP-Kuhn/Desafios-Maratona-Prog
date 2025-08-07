#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  vll s(n);
  unordered_map<ll, ll> m, r;
  for (ll i=0; i<n; i++){
    ll x;
    cin >> x;
    m[x] = x;
  }

  for (ll i=0; i<n; i++){
    ll x;
    cin >> x;
    r[x] = x;
  }

  for (ll &x : s) cin >> x;

  ll ans{-1};
  for (ll i : s){
    if (m.count(i) && r.count(i)){
      ans = max(ans, i);
    }
  }

  cout << ans << '\n';

  return 0;
}

