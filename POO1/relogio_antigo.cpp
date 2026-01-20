#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll h, m, horas{}, minutos{};
  while(cin >> h >> m){
    horas = h/30;
    minutos = m/6;

    if (horas > 9){
      cout <<  horas << ':';
      if (minutos > 9){
        cout << minutos << '\n';
      } else {
        cout << '0' << minutos << '\n';
      }
    } else {
      cout << '0' << horas << ':';
      if (minutos > 9){
        cout << minutos << '\n';
      } else {
        cout << '0' << minutos << '\n';
      }
    }
  }

  return 0;
}

