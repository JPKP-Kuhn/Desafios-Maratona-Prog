#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; scanf("%lld", &t);
  while(t--){
    ll n; scanf("%lld", &n);
    vll v(n);
    for (ll &x : v) scanf("%lld", &x);
    sort(v.begin(), v.end());
    for (ll i{}; i<n; i++){
      if (i > 0) printf(" ");
      printf("%lld", v[i]);
    }
    printf("\n");
  }

  return 0;
}

