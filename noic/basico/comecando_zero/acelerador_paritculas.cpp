#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll d; cin >> d;
  d-=3;
  d%=8;
  if (d==3) cout << 1 << '\n';
  else if (d==4) cout << 2 << '\n';
  else cout << 3 << '\n';

  return 0;
}

