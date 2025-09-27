#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, q; cin >> n >> q;
  vll num(n);
  for (ll &x : num) cin >> x;

  for (ll k=0; k<q; k++){
    ll r; cin >> r;
    ll c{};

    for (ll i : num){
      long double root = pow(i, 1.0L / r);
      if (round(root) == root) c++;
    }
    cout << c << '\n';
  }

  return 0;
}

