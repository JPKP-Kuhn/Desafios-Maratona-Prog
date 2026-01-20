#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  while(cin >> n){
    ll c{};
    cin.ignore();
    for (ll a{}; a<n; a++){
      string esp, raca, nome, branco;
      getline(cin, esp);
      getline(cin, raca);
      getline(cin, nome);
      getline(cin, branco);

      if (esp != "cachorro") continue;
      if (find(nome.begin(), nome.end(), ' ') == nome.end()) continue;
      stringstream ss(nome);
      string pal;
      bool t{};
      while (ss >> pal){
        if (pal[0] == raca[0]){
          t=true; break;
        }
      }
      if (t) c++;
    }
    cout << c << '\n';
  }

  return 0;
}

