#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T; cin >> T;
  while(T--){
    ll n; cin >> n;
    ll p=1;
    for (ll i=1; i<=n; i++) p*=i;
    cout << p << '\n';
  }

  return 0;
}

