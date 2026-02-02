#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t1, t2, t3; cin >> t1 >> t2 >> t3;
  vll v = {t1, t2, t3};
  sort(v.begin(), v.end());
  for (ll i : v){
    if (i==t1)cout << 1 << '\n';
    else if (i==t2) cout << 2 << '\n';
    else cout << 3 << '\n';
  }

  return 0;
}

