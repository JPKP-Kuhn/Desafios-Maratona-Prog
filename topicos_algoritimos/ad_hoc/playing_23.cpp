#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll pj{}, pm{};

ll trata(ll n) {
  if (n > 10) {
    return 10;
  } else {
    return n;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  map<ll, ll> baralho;
  pair<ll, ll> john;
  cin >> john.first >> john.second;
  baralho[john.first]++;
  baralho[john.second]++;
  pj += trata(john.first);
  pj += trata(john.second);
  pair<ll, ll> mary;
  cin >> mary.first >> mary.second;
  baralho[mary.first]++;
  baralho[mary.second]++;
  pm += trata(mary.first);
  pm += trata(mary.second);

  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    pj += trata(x);
    pm += trata(x);
    baralho[x]++;
  }

  for (ll i = 1; i <= 13; i++) {
    if (baralho[i] == 4)
      continue;
    ll m = pm + trata(i);
    ll j = pj + trata(i);
    if ((m == 23 || j > 23) && m <= 23) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';

  return 0;
}
