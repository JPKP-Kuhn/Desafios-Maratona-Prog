#include <bits/stdc++.h>
#include <ios>
#include <iterator>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll predios{};
  cin >> predios;

  vll predios_andares(predios);
  for (ll i=0;i<predios;i++){
    cin >> predios_andares[i];
  }

  // Força bruta
  ll distMaior{};
  pair<ll, ll>maiorPar; // Melhor par de prédios
  ll alturaEsq{};
  alturaEsq = predios_andares[0];
  ll indexEsq{};
  ll caminhada{};
  for (ll i=1;i<predios;i++){
    caminhada++;
    if (predios_andares[i] > alturaEsq+caminhada){
      alturaEsq = predios_andares[i];
      indexEsq = i;
    }
  }
  ll alturaDir = predios_andares[predios_andares.size()-1];
  ll dcaminhada{};
  ll indexDir = predios_andares.size()-1;
  for (ll j=predios_andares.size()-2;j>0;j--){
    dcaminhada++;
    if (predios_andares[j] > alturaDir+dcaminhada){
      alturaDir = predios_andares[j];
      indexDir = j;
    }
  }
  maiorPar = make_pair(alturaEsq, alturaDir);

  distMaior = maiorPar.first + maiorPar.second + abs(indexDir - indexEsq);
  cout << distMaior << '\n';
  return 0;
}

