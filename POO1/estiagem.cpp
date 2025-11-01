// 1023
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, c{};
  while(cin >> n && n){
    map<ll, ll> q;
    ll soma{}, div{};
    for (ll i=0; i<n; i++){
      ll x, y; cin >> x >> y;
      soma+=y; div+=x;
      ll k = floor(y/x);
      q[k]+=x;
    }
    double media = (double)soma/div;
    media = floor(media*100)/100.0;

    cout << "Cidade# " << ++c << ":\n";
    for (auto &[k, v] : q){
      cout << v << '-' << k << ' ';
    }
    cout << '\n';
    cout << fixed << setprecision(2) << "Consumo medio: " << media << " m3.\n\n";
  }

  return 0;
}

