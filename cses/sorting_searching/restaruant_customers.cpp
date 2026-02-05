#include <bits/stdc++.h>
#include <set>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  set<pair<ll, char>> p;
  for (ll i{}; i<n; ++i){
    ll a, b; cin >> a >> b;
    p.insert({a, 'e'});
    p.insert({b, 's'});
  }

  ll t{}, m{};
  for (auto &[a, c] : p){
    if (c=='e'){
      t++; m=max(m, t);
    } else {
      m=max(m, t); t--;
    }
  }
  cout << m << '\n';

  return 0;
}

