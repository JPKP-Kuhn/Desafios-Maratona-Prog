#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  ll instancia{};
  while(cin >> n && n){
    unordered_map<ll, ll>pontos_vd;
    unordered_map<ll, ll>cesta_average;
    unordered_map<ll, ll>pontos_marcados;
    unordered_map<ll, ll>pontos_sofridos;

    for (ll i{}; i<n * (n-1)/2; i++){
      ll x, y, z, w; cin >> x >> y >> z >> w;
      if (y > w){
        pontos_vd[x]+=2; pontos_vd[z]++;
      } else if (y < w){
        pontos_vd[z]+=2; pontos_vd[x]++;
      }
      pontos_marcados[x]+=y; pontos_sofridos[x]+=w;
      pontos_marcados[z]+=w; pontos_sofridos[z]+=y;
    }

    vll v(n); iota(v.begin(), v.end(), 1);
    if (instancia>0) cout << '\n';
    cout << "Instancia " << ++instancia << '\n';

    sort(v.begin(), v.end(), [&](ll a, ll b){
        if (pontos_vd[a] != pontos_vd[b])
          return pontos_vd[a] > pontos_vd[b];

        ll ma = pontos_marcados[a], mb = pontos_marcados[b];
        ll sa = pontos_sofridos[a], sb = pontos_sofridos[b];
        if (sa==0) return true;
        else if (sb==0) return false;
        else {
          if (ma * sb != mb * sa) return ma * sb > mb * sa;
        }

        if (pontos_marcados[a] != pontos_marcados[b])
          return pontos_marcados[a] > pontos_marcados[b];

        return a < b;
        });

    for (ll i{}; i<n; i++){
      if (i > 0) cout << ' ';
      cout << v[i];
    }
    cout << "\n";
  }

  return 0;
}

