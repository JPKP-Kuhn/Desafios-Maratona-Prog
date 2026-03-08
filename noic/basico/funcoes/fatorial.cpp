#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll fat(ll n){
  if (n==0) return 1;

  ll r=1;
  for (ll i=1; i<=n; i++) r*=i;

  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  cout << fat(n) << '\n';

  return 0;
}

