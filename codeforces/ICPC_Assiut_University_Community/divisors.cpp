#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  for (ll i=1; i<=n; i++){
    if (n%i==0) cout << i << '\n';
  }

  return 0;
}

