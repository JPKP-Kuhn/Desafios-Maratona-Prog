#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b, c; cin >> a >> b >> c;
  cout << min({a, b, c}) << ' ' << max({a, b, c}) << '\n';

  return 0;
}

