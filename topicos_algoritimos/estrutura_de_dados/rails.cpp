#include <bits/stdc++.h>
#include <stack>
using namespace std;
using ll = long long;

int main() {
  ll n;

  while(cin >> n && n != 0) {
    while (true) {
      vector<ll> alvo(n);
      bool possivel = true;

      cin >> alvo[0];
      if (alvo[0] == 0) break; // fim do bloco
      for (ll i =1;i < n; i++){
        cin >> alvo[i];
      }

      stack<ll> estacao;
      ll atual = 1; // Próximo vagão de A

      for (ll i =0; i < n; i++) {
        ll desejado = alvo[i];

        // Empilha até o desejado apracerer no topo
        while (atual <= n && (estacao.empty() || estacao.top() != desejado)) {
          estacao.push(atual);
          atual++;
        }

        if (estacao.top() == desejado && !estacao.empty()) {
          estacao.pop();
        } else {
          possivel = false;
          break;
        }
      }
      // Acabou o bloco
      cout << (possivel ? "Yes" : "No") << endl;
    }
    cout << endl;
  }
  return 0;
}

