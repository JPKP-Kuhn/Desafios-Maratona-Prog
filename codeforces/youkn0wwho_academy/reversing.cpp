#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  vll v(n);
  for(ll &x : v) cin >> x;
  for (ll i=n-1; i>=0; i--){
    cout << v[i] << ' ';
  }
  cout << '\n';

  return 0;
}

