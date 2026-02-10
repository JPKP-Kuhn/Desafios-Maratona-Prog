#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  ll d{}, sd{};
  vector<vll> m(n, vll(n));
  for (ll i{}; i<n; i++){
    for (ll j{}; j<n; j++){
      cin >> m[i][j];
    }
  }

  for (ll i{}; i<n; i++){
    d+=m[i][i];
    sd+=m[i][n-i-1];
  }
  cout << abs(d-sd) << '\n';

  return 0;
}

