#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll x, c{}; cin >> x;
  while(x--){
    ll n; cin >> n;
    c+=n-1;
  }
  cout << c << '\n';

  return 0;
}

