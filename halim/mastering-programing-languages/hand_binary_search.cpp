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
  ll b; cin >> b;

  ll a{}; --n;
  bool f{};
  while (a <= n){
    ll m = (a+n)/2;
    if (v[m] == b){
      f = true; break;
    } else if (v[m] < b){
      a = m+1;
    } else {
      n = m-1;
    }
  }
  cout << (f ? "Achou" : "Não") << '\n';


  return 0;
}

