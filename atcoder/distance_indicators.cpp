#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vll a(n);
  unordered_map<ll, ll> mapa;
  for (ll &x : a) cin >> x;

  ll c{};
  for (ll i=0; i<n; i++){
    if (mapa.count(i-a[i])){
      c+=mapa[i-a[i]];
    }
    mapa[i+a[i]]++;
  }

  cout << c << '\n';
  return 0;
}

