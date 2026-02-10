#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m; cin >> n >> m;
  unordered_map<ll, ll> d;
  for (ll i{}; i<n; i++){
    for (ll j{}; j<m; j++){
      ll x; cin >> x;
      d[x]++;
    }
  }
  ll x; cin >> x;
  cout << (d.count(x) ? "will not take number" : "will take number") << '\n';

  return 0;
}

