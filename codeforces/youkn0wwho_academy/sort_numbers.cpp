#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b, c; cin >> a >> b >> c;
  vll v = {a, b, c};
  sort(v.begin(), v.end());
  for (ll i : v) cout << i << '\n';
  cout << '\n';
  cout << a << '\n';
  cout << b << '\n';
  cout << c << '\n';

  return 0;
}

