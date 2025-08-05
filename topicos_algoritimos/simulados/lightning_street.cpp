#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m, L; cin >> n >> m >> L;
  vll position(n);
  sort(position.begin(), position.end());
  for (ll &x : position) cin >> x;
  vll ilumination(m);
  for (ll &y : ilumination) cin >> y;

  ll asn = -1;

  for (ll i : ilumination){
    vpll intervalos;
    for (ll j : position){
      ll start = max(0LL, j-i);
      ll end = min(L, j+i);
      intervalos.emplace_back(start, end);
    }

    sort(intervalos.begin(), intervalos.end());
    bool f = false;
    ll r{};
    for (auto &[p1, p2] : intervalos){
      if (p1 > r) break;
      r = max(r, p2);
      if (r >= L){
        f = true;
        break;
      }
    }

    if (f){
      if (asn == -1 || i < asn) asn = i;
    }
  }


  cout << asn << '\n';

  return 0;
}

