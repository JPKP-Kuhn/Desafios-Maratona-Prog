#include <bits/stdc++.h>
#include <ios>
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

  ll t{};
  while (cin >> t && t != 0){
    map<vll, ll> popular_combination;
    for (ll i=0; i<t; i++){
      vll cursos(5);

      for (ll j=0; j<5; j++){
        cin >> cursos[j];
      }

      sort(cursos.begin(), cursos.end());
      popular_combination[cursos]++;
    }

    ll mais_frequente{};
    for (auto& i : popular_combination){
      mais_frequente = max(mais_frequente, i.second);
    }

    ll estudantes{};
    for (auto& j : popular_combination){
      if (j.second == mais_frequente){
        estudantes+=j.second;
      }
    }

    cout << estudantes << '\n';
  }
  return 0;
}

