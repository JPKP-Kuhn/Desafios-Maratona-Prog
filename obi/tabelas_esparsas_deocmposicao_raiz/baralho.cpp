#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

const double PI = 3.14159265358979323846;
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

void saida(char l, map<char, ll> &tam, map<char, string> &erro) {
  if (erro[l] == "erro") {
    cout << "erro\n";
  } else if (tam[l] < 13) {
    cout << 13 - tam[l] << '\n';
  } else {
    cout << 0 << '\n';
  }
}

int main() {
  _

      string s;
  cin >> s;

  map<char, map<string, ll>> baralho;
  map<char, ll> tam;
  map<char, string> erro;

  for (ll i{}; i < s.size() - 2; i += 3) {
    string carta{};
    carta += s[i];
    carta += s[i + 1];

    baralho[s[i + 2]][carta]++;
    tam[s[i + 2]]++;

    if (baralho[s[i + 2]][carta] > 1)
      erro[s[i + 2]] = "erro";
  }

  // copas
  saida('C', tam, erro);
  // espadas
  saida('E', tam, erro);
  // ouros
  saida('U', tam, erro);
  // paus
  saida('P', tam, erro);

  return 0;
}
