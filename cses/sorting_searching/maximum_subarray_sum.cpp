#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  vll v(n);
  for (ll &x : v) cin >> x;

  ll best=v[0], sum=v[0];
  for (ll i=1; i<n; ++i){
    sum = max(v[i], sum+v[i]);
    best = max(best, sum);
  }
  cout << best << '\n';

  return 0;
}

