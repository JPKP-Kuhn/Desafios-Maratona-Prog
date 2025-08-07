#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  vll v(n);
  for (ll &x : v) cin >> x;

  ll res = v[0];
  ll maxEnd = v[0];
  for (ll i=1; i<n; i++){
    maxEnd = max(v[i], maxEnd + v[i]);

    res = max(res, maxEnd);
  }

  cout << res << '\n';
  return 0;
}

