#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n{};
  cin >> n;
  vector<vll> sinuca(n);
  ll x{};
  for (ll i=0; i<n; i++){
    cin >> x;
    sinuca[0].push_back(x);
  }

  ll tamanho = n-1;
  ll camada = 1;
  ll sizeAnterior = sinuca[0].size();

 while (tamanho > 0 && camada < n){
    for (ll j=0; j<sizeAnterior-1; j++){
      if (sinuca[camada-1][j] != sinuca[camada-1][j+1]) {
        sinuca[camada].push_back(-1);
      } else {
        sinuca[camada].push_back(1);
      }
    }
    tamanho--;
    camada++;
    sizeAnterior = sinuca[camada-1].size();
  } 

  cout << (sinuca[n-1][0] == -1 ? "branca" : "preta") << '\n';

  return 0;
}

