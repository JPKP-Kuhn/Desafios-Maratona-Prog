#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll l, c; cin >> l >> c;
  if (l == c) cout << 1 << '\n';
  else if ((l%2==1 && c%2==0) || (l%2==0 && c%2==1)) cout << 0 << '\n';
  else if ((l%2==0 && c%2==0) ||  (l%2==1 && c%2==1)) cout << 1 << '\n';

  return 0;
}

