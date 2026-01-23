#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  ll sx{}, sy{}, sz{};
  while(n--){
    ll x, y, z; cin >> x >> y >> z;
    sx+=x; sy+=y; sz+=z;
  }
  cout << (sx == 0 and sy == 0 and sz == 0 ? "YES\n" : "NO\n");

  return 0;
}

