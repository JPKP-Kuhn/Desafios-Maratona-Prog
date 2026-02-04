#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  ll q{};
  while(n--){
    ll l, c; cin >> l >> c;
    if (l > c) q+=c;
  }
  cout << q << '\n';

  return 0;
}

