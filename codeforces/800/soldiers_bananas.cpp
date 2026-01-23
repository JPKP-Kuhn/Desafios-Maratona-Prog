#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll k, n, w; cin >> k >> n >> w;
  ll cost{};
  for (ll i=1; i<=w; ++i){
    cost+=i*k;
  }
  if (cost>n) cout << cost-n << '\n';
  else cout << 0 << '\n';

  return 0;
}

