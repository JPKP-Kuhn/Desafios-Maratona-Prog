#include <bits/stdc++.h>
#include <cstdio>
#include <ios>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll instancia{};
  cin >> instancia;
  cin.ignore();
  while (instancia--){
    ll palavras_dicionario{}, linhas_musica{};
    cin >> palavras_dicionario >> linhas_musica;
    cin.ignore();

    unordered_map<string, string> dicionario;

    string pJap, pPort;
    for (ll i=0; i<palavras_dicionario; i++){
      getline(cin, pJap);
      getline(cin, pPort);

      dicionario[pJap] = pPort;
    }

    string linha{};
    for (ll j=0; j<linhas_musica; j++){
      getline(cin, linha);
      stringstream ss(linha);
      string palavra;
      bool primeiro = true;

      while (ss >> palavra) {
        if (!primeiro) cout << ' ';
        primeiro = false;
        if (dicionario.count(palavra)){
          cout << dicionario[palavra];
        } else {
          cout << palavra;
        }
      }
      cout << '\n';
    }
    cout << '\n';
  }

  return 0;
}

