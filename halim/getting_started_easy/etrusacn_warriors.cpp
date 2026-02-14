#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// sequence 1, 3, 6, 10, 15, ...
// r1 = 1;
// r2 = r1 + 2
// r3 = r2 + 3; r1 + 2 + 3;
// rn = r1 + 2 + 3 + 4 + ... + n; rn = somatorio de i, partindo de 1 até n; n(n+1)/2
// n(n+1)/2 <= P
// n² + n - 2P = 0
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll n; cin >> n;
    ll r = (-1 + sqrt(1 + 8*n))/2;
    cout << r << '\n';
  }

  return 0;
}

