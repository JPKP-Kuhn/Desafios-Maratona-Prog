#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  string line;
  getline(cin, line);
  t = stoi(line);
  getline(cin, line);
  for(ll i=0; i<t; i++){
    string s{};
    map<string, ll> arvore;
    double total{};
    while(getline(cin, s)){
      if (s.empty()) break;
      arvore[s]++;
      total++;
    }
    for (auto &[a, n] : arvore){
      cout << a << ' ' << fixed << setprecision(4) << (arvore[a]/total)*100 << '\n';
    }
    if (i<t-1) cout << '\n';
  }

  return 0;
}

