#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  map<ll, string> botas;
  for (ll i{}; i<n; i++){
    ll c; string p; cin >> c >> p;
    botas[c]+=p;
  }
  ll par{};
  for (auto &[k, v] : botas){
    ll dir = count(v.begin(), v.end(), 'D');
    ll esq = count(v.begin(), v.end(), 'E');
    if (dir != 0 && esq != 0){
      par+=min(dir, esq);
    }
  }
  cout << par << '\n';

  return 0;
}

