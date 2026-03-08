#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, f, d; cin >> m >> f >> d;
  int v = m -f-d;
  cout << max({v, f, d}) << '\n';

  return 0;
}

