#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll n;
bool f=false;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while(cin >> n && n){
    cin.ignore();
    vector<tuple<string, string, string>> camisa(n);
    for (ll i{}; i<n; i++){
      string nome, cor, tamanho; getline(cin, nome);
      cin >> cor >> tamanho;
      cin.ignore();
      camisa[i] = {cor, tamanho, nome};
    }
    sort(camisa.begin(), camisa.end(), [](const auto &a, const auto&b){
        auto &[corA, tamA, nomeA] = a;
        auto &[corB, tamB, nomeB] = b;
        if (corA != corB) return corA < corB;
        if (tamA != tamB) return tamA > tamB;
        return nomeA < nomeB;
        });
    if (f) cout << '\n';
    for (auto &[cor, tamanho, nome] : camisa){
      cout << cor << ' ' << tamanho << ' ' << nome << '\n';
    }
    f=true;
  }

  return 0;
}

