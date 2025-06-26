#include <bits/stdc++.h>
#include <ios>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

ll n, m;
pair<ll, ll> left_end;
pair<ll, ll> right_end;
vector<pair<ll, ll>> domino;
vector<pair<ll, ll>> caminho_correto;
vector<bool> usada;
bool resposta = false;

void backtracking(){
  if (resposta) return;

  // Quantas pecas podem ser encaixadas no primeiro
  // Encaixo as peças uma por uma, salvo quais peças uncionaram, para poder depois recuar
  if (caminho_correto.size() == n+1){
    if (caminho_correto.back().second == right_end.first){
      cout << "Caminho correto\n";
      resposta = true;
    }
    return;
  }

  ll ult_num = caminho_correto.back().second;

  for (ll i =0; i<m; i++){
    if (!usada[i]){
      auto [a, b] = domino[i];

      if (a == ult_num){
        usada[i] = true;
        caminho_correto.push_back({a, b});
        cout << "Colocando a peça: " << a << ' ' << b << '\n';
        backtracking();
        // Se não der certo, retorna;
        cout << "Não funcionou com a\n";
        caminho_correto.pop_back();
        usada[i] = false;
      }
      else if (b == ult_num){
        usada[i] = true;
        caminho_correto.push_back({b, a});
        cout << "Colocando a peça: " << b << ' ' << a << '\n';
        backtracking();
        // Se não der certo, retorna;
        cout << "Não funcionou com b\n";
        caminho_correto.pop_back();
        usada[i] = false;
      }

      cout << "Caminho: \n";
      for (auto [x, y] : caminho_correto){
        cout << x << ' ' << y << '\n';
      }
      cout << right_end.first << ' ' << right_end.second << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  while (n!=0) {
    cin >> m;
    // left
    ll a, b;
    cin >> a >> b;
    left_end = make_pair(a, b);

    // right
    ll c, d;
    cin >> c >> d;
    right_end = make_pair(c, d);

    domino.clear();
    domino.resize(m);
    caminho_correto.clear();
    usada.assign(m, false);
    resposta = false;
    for (ll i=0; i < m; i++){
      ll x, y;
      cin >> x >> y;
      domino[i] = make_pair(x, y);
    }
    caminho_correto.push_back(left_end);
    backtracking();

    cout << (resposta ? "YES\n" : "NO\n");
    cin >> n;
  }

  return 0;
}

