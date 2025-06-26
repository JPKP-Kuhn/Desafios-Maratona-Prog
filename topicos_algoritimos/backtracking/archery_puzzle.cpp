#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

vll solucao;
ll menosFlechas;
void backtracking(ll alvoRestante, vll& pontos, vll& solAtual){
  if (solAtual.size() >= menosFlechas) return;

  if (alvoRestante == 0){
    if (solAtual.size() < menosFlechas || (solAtual.size() == menosFlechas && solAtual > solucao)){
      menosFlechas = solAtual.size();
      solucao = solAtual;
    }
    return;
  }

  if (alvoRestante < 0) return;

  for (ll i= pontos.size()-1; i>=0; i--){
    if (pontos[i] <= alvoRestante){
      solAtual.push_back(pontos[i]);
      backtracking(alvoRestante - pontos[i], pontos, solAtual);
      solAtual.pop_back();
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t{};
  cin >> t;
  for (ll i=1; i<=t; i++){
    ll n, pontuacao;
    cin >> n >> pontuacao;
    vll pontos(n);
    for (ll j=0; j<n; j++){
      cin >> pontos[j];
    }

    solucao.clear();
    menosFlechas = INF;
    vll solAtual;
    backtracking(pontuacao, pontos, solAtual);

    if (!solucao.empty()){
      cout << "Case " << i << ": " << '[' << solucao.size() << ']';
      for (ll num : solucao){
        cout << ' ' << num;
      }
      cout << '\n';
    } else {
      cout << "Case " << i << ": impossible\n";
    }
  }

  return 0;
}

