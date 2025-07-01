#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e6 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

ll vessels, containers;
vll milk(MAXN);

bool possivel(ll cap_max){
  ll containerUsado = 1;
  ll somaVessel{};

  for (ll i=0; i<vessels; i++){
    if (milk[i] > cap_max) return false;
    somaVessel+=milk[i];
    if (somaVessel > cap_max){
      containerUsado++;
      somaVessel = milk[i];
    }
    if (containerUsado > containers) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> vessels >> containers){
    ll leiteTotal{};
    ll maisLeite{};
    for (ll i=0; i<vessels; i++){
      cin >> milk[i];
      leiteTotal+=milk[i];
      maisLeite = max(milk[i], maisLeite);
    }

    ll low = maisLeite;
    ll high = leiteTotal;
    ll menor_max = high;
    while (low <= high){
      ll mid = (high + low) / 2;
      bool pos = possivel(mid);
      if (pos){
        menor_max = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    cout << menor_max << '\n';
  }

  return 0;
}

