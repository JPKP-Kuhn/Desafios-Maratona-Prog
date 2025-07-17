#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  while (cin >> n && n != 0){
    unordered_map<string, string> nome_ass;
    for (ll i=0; i<n; i++){
      string nome, ass;
      cin >> nome >> ass;
      nome_ass[nome] = ass;
    }
    ll aula, falso{};
    cin >> aula;
    for (ll i=0; i<aula; i++){
      string nome, ass;
      cin >> nome >> ass;
      ll diff{};
      for (ll j=0, s = nome_ass[nome].length(); j<s; j++){
        if (ass[j] != nome_ass[nome][j]){
          diff++;
          if (diff == 2){ 
            falso++;
            break;
          }
        }
      }
    }
    cout << falso << '\n';
  }

  return 0;
}

