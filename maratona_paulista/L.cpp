#include <bits/stdc++.h>
#include <ios>
#include <stack>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n{};
  cin >> n;
  vector<stack<ll>> pilha_livros(n);
  for (ll i=0;i<n;i++){
    ll x{};
    cin >> x;
    for (ll j=0;j<x;j++){
      ll y{};
      cin >> y;
      pilha_livros[i].push(y);
    }
  }

  if (n >= 3 || n == 1){
    cout << 'S' << '\n';
  } else {
    stack<ll> temp = pilha_livros[0];
    while(!temp.empty()){
      pilha_livros[1].push(temp.top());
      temp.pop();
    }
    // Descobrir se é uma sequência
    ll correto = pilha_livros[1].top();
    bool primeiraVez = false;
    pilha_livros[1].pop();
    ll atual{};
    while(!pilha_livros[1].empty()){
      atual = pilha_livros[1].top();
      pilha_livros[1].pop();
      if (atual == correto) {
        continue;
      } else if (atual != correto && !primeiraVez) {
        correto = atual;
        primeiraVez = true;
      } else {
        cout << "N\n";
        return 0;
      }
    }
    cout << 'S' << '\n';
  }

  return 0;
}

