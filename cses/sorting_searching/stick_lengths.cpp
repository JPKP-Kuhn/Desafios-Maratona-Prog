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

  sort(v.begin(), v.end());
  ll cost{};

  if (v.size()%2==1) cost = v[(n/2)];
  else cost = (v[(n/2)] + v[(n/2)-1])/2;

  ll r{};
  for (ll i : v){
    r += abs(cost - i);
  }
  cout << r << '\n';

  return 0;
}

