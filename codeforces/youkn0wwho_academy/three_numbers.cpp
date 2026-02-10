#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll k, s; cin >> k >> s;
  ll c{};

  for (ll x{}; x<=k; x++){
    for (ll y{}; y<=k; y++){
      ll z = s - x - y;
      if (z>k || z < 0) continue;
      c++;
    }
  }
  cout << c << '\n';

  return 0;
}

