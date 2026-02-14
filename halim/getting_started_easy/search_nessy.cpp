#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll n, m; cin >> n >> m;
    cout << (n/3) * (m/3) << '\n';
  }

  return 0;
}

