#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b, c, d; cin >> a >> b >> c >> d;
  vll v = {a, b, c, d};
  sort(v.begin(), v.end());
  cout << v[3] + v[0] - v[1] - v[2] << '\n';

  return 0;
}

