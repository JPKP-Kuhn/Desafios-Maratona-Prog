#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll l, r, k, c{};
  cin >> l >> r >> k;
  for (ll i=l; i<=r; i++){
    if (i % k == 0) c++;
  }
  cout << c << '\n';

  return 0;
}

