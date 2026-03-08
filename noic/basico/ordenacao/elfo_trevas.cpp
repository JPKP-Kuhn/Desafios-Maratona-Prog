#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t, cenario{}; cin >> t;
  while(t--){
    ll n, m; cin >> n >> m;
    unordered_map<string, vector<double>> renas;
    vector<string> nomes(n);
    for (ll i{}; i<n; i++){
      string nome;
      double peso, idade, altura;
      cin >> nome >> peso >> idade >> altura;
      renas[nome] = {peso, idade, altura};
      nomes[i]=nome;
    }

    sort(nomes.begin(), nomes.end(), [&](string a, string b){
        if (renas[a][0] != renas[b][0]) return renas[a][0] > renas[b][0];

        if (renas[a][1] != renas[b][1]) return renas[a][1] < renas[b][1];

        if (renas[a][2] != renas[b][2]) return renas[a][2] < renas[b][2];

        return a < b;
        });

    vector<string> treno(m);
    for (ll i{}; i<m; i++){
      treno[i] = nomes[i];
    }

    cout << "CENARIO {" << ++cenario << "}\n";
    for (ll i=1; i<=m; i++){
      cout << i << " - " << treno[i-1] << '\n';
    }
  }

  return 0;
}

