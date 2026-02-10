#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll x, n; cin >> x >> n;
  ll sum{};
  for (ll i=2; i<=n; i+=2){
    sum+=pow(x, i);
  }
  cout << sum << '\n';

  return 0;
}

