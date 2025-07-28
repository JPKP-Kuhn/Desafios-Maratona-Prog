#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k;
  cin >> n >> k;
  vll v(n);
  for (ll &x : v) cin >> x;
  vll::iterator it = v.begin();
  vll::iterator rit = v.end();

  for (ll i=0; i<k; i++){
    if (i%2==0) it++;
    else rit--;
  }
  if (k % 2 == 0) {
    for (auto p = it; p < rit; ++p) {
      cout << *p << ' ';
    }
  } else {
    for (auto p = rit; p != it; ) {
      --p;
      cout << *p << ' ';
    }
  }
  cout << '\n';

  return 0;
}

