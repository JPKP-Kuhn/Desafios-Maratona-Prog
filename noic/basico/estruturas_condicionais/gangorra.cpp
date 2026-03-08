#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll p1, c1, p2, c2; cin >> p1 >> c1 >> p2 >> c2;
  ll um = p1*c1, dois = p2*c2;
  if (um == dois) cout << 0 << '\n';
  else cout << (um>dois ? -1 : 1) << '\n';

  return 0;
}

