#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m, k; cin >> n >> m >> k;

  map<ll, ll> perpro;
  for (ll i=1; i<=n; i++) perpro[i] = 0;
  vll r{};
  while(k--){
    ll a, b; cin >> a >> b;
    perpro[a]++;
    if (perpro[a] == m) r.push_back(a);
  }

  for (ll i : r){
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}

