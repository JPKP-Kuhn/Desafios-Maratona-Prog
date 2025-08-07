#include <bits/stdc++.h>
using namespace std;
using lld = long double;
using ll = long long;

pair<ll, ll> divis(pair<ll, ll> n){
  ll m = min(n.first, n.second);
  for (ll i=2; i <=m; i++){
    while(n.first % i == 0 && n.second % i == 0){
      n.first /= i; n.second /= i;
    }
  }
  return n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double a, b, c, d; cin >> a >> b >> c >> d;
  // a/b + c/d 
  ll num = (d*a + b*c);
  ll dem = (b * d);
  pair<ll, ll> n;
  n = divis(make_pair(num, dem));

  cout << n.first << ' ' << n.second << '\n';

  return 0;
}

