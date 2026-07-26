#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  ll estado{-1}, saida{};
  ll estadoespera{-1};
  bool espera = false;
  while (n--) {
    ll t, e;
    cin >> t >> e;
    if (t >= saida && espera) {
      saida += 10;
      estado = estadoespera;
      espera = false;
    }

    if (estado == -1) {
      estado = e;
      saida = t + 10;
    } else if (e == estado) {
      if (t < saida) {
        saida = max(saida, t + 10);
      } else {
        saida = t + 10;
        estado = e;
      }
    } else {
      if (t >= saida) {
        estado = e;
        saida = t + 10;
      } else {
        espera = true;
        estadoespera = e;
      }
    }
  }
  if (espera) {
    saida += 10;
  }
  cout << saida << '\n';
  return 0;
}
