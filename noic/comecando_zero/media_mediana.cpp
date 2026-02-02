#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b; cin >> a >> b;
  // (a + b + c)/3 == mediana
  ll c = 3*min(a, b)-a-b;
  cout << c << '\n';

  return 0;
}

