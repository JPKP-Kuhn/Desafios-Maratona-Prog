#include <bits/stdc++.h>
#include <ios>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;
const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

vector<pair<ll, ll>> frac;

bool verRepetido(ll num){
  bool d[10];
  fill(d, d+10, false);
  for (ll i=0; i<5; i++){
    ll digit = num%10;
    if(d[digit]){
      return false;
    }
    num/=10;
    d[digit] = true;
  }
  return true;
}

bool verDisjunto(ll num, ll den){
  bool d[10];
  fill(d, d+10, false);
  for (ll i=0; i<5; i++){
    ll digit = num%10;
    d[digit] = true;
    num/=10;
  }
  for (ll i=0;i <5; i++){
    ll digit = den%10;
    if (d[digit]){
      return false;
    }
    den/=10;
  }
  return true;
}

void backtrack(ll n){
  for (ll denominador = 1234; denominador <= 98765; denominador++){
    if (!verRepetido(denominador)) continue;
    ll numerador = denominador * n;
    if (numerador > 99999){
      break;
    }
    if (!verRepetido(numerador)) continue;
    if (!verDisjunto(numerador, denominador)) continue;
    frac.push_back({numerador, denominador});
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  // Solução 1: Lê todos os casos primeiro
  vector<ll> casos;
  ll n;
  
  while (cin >> n && n != 0){
    casos.push_back(n);
  }
  
  for (int i = 0; i < casos.size(); i++){
    frac.clear();
    backtrack(casos[i]);
    sort(frac.begin(), frac.end());
    
    if (!frac.empty()){
      for (auto [a, b] : frac){
        cout << setfill('0') << setw(5) << a << " / " << setfill('0') << setw(5) << b << " = " << casos[i] << '\n';
      }
    } else {
      cout << "There are no solutions for " << casos[i] << ".\n";
    }
    
    // Linha em branco após cada caso, exceto o último
    if (i < casos.size() - 1){
      cout << '\n';
    }
  }
  
  return 0;
}
