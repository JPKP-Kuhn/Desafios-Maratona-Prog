#include <algorithm>
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
  iter_swap(max_element(v.begin(), v.end()), min_element(v.begin(), v.end()));
  for (ll i : v){
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}

