#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k; cin >> n >> k;
  vll v(n);
  for (ll &x : v) cin >> x;
  ll score = v[k-1];
  ll c{};
  for (ll i : v){
    if (i > 0 && i >= score) c++;
  }

  cout << c <<'\n';

  return 0;
}

