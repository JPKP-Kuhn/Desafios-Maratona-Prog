#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  set<ll> num;
  while(n--){
    ll x; cin >> x;
    num.insert(x);
  }
  for (ll i : num){
    cout << i << '\n';
  }

  return 0;
}

