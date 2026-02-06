#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  vpl film(n);
  for(auto &[x, y] : film) cin >> y >> x;
  sort(film.begin(), film.end());
  ll c=1;
  ll timeE=film[0].first;
  for (ll i=1; i<n; i++){
    if (film[i].second >= timeE){
      c++; timeE=film[i].first;
    }
  }
  cout << c << '\n';

  return 0;
}

