#include <bits/stdc++.h>
#include <ios>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

string s, ss;
map<char, vll>psSimbolo;
ll t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s >> t;
  for (ll i=0; i<s.length(); i++){
    psSimbolo[s[i]].push_back(i);
  }
  while (t--) {
    cin >> ss;

    ll ultimo = -1, inicio = -1, fim = -1;
    bool match = true;

    for (char c : ss){
      if (!psSimbolo.count(c)){
        match = false;
        break;
      }

      auto it = upper_bound(psSimbolo[c].begin(), psSimbolo[c].end(), ultimo);
      if (it == psSimbolo[c].end()){
        match = false;
        break;
      }

      ultimo = *it;
      if (inicio == -1) inicio = ultimo;
      fim = ultimo;

    }

    if (match){
      cout << "Matched " << inicio << ' ' << fim << '\n';
    } else {
      cout << "Not matched\n";
    }
  }

  return 0;
}

