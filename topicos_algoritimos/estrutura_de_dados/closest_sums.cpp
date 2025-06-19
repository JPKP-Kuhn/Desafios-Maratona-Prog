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
  ll caso = 1;
  while (cin >> n && n != 0) {
    vll numeros(n);
    for (ll i=0;i<n;i++){
      cin >> numeros[i];     
    }
    set<ll> set;
    for (ll i=0; i<n; i++){
      for (ll j=i+1; j<n; j++){
        set.insert(numeros[i] + numeros[j]);
      }
    }
    ll m{};
    cin >> m;
    vll queries(m);
    for (ll i=0;i<m;i++){
      cin >> queries[i];
    }
    cout << "Case " << caso << ':' << '\n';
    for (ll j=0; j<queries.size(); j++){
      auto it = set.lower_bound(queries[j]);
      ll melhor_soma{};
      ll menor_diferenca = INF;
      if (it != set.end()) {
        ll dif = abs(*it - queries[j]);
        if (dif < menor_diferenca){
          melhor_soma = *it;
          menor_diferenca = dif;
        }
      }
      if (it != set.begin()){
        --it;
        ll dif = abs(*it - queries[j]);
        if (dif < menor_diferenca){
          menor_diferenca = dif;
          melhor_soma = *it;
        }
      }
      cout << "Closest sum to " << queries[j] << " is " << melhor_soma << '.' << '\n';
    }
    caso++;
  }

  return 0;
}

