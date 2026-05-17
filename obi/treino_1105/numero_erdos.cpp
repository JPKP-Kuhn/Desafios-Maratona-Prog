#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;

int main() {
  _ ll a;
  ll teste{};
  while (cin >> a && a) {
    set<pair<string, string>> autores;
    vector<vector<string>> artigos(a);
    cin.ignore();
    for (ll i = 0; i < a; i++) {
      string line;
      getline(cin, line);

      if (line.empty())
        continue;

      if (line.back() == '.')
        line.pop_back();

      stringstream ss(line);
      string nome;
      while (getline(ss, nome, ',')) {
        if (!nome.empty() && nome[0] == ' ')
          nome.erase(nome.begin());

        pair<string, string> sob_nome;
        int pos = nome.find(' ');
        sob_nome.first = nome.substr(0, pos);
        sob_nome.second = nome.substr(pos + 1);
        autores.insert({sob_nome.second, sob_nome.first});
        artigos[i].pb(nome);
      }
    }
    unordered_map<string, ll> nome_no;
    ll no{};
    for (auto &[nome, sobre] : autores) {
      string total = sobre + ' ' + nome;
      nome_no[total] = no++;
    }
    ll origem = -1;
    if (nome_no.count("P. Erdos"))
      origem = nome_no["P. Erdos"];

    vector<vll> adj(autores.size());
    for (ll art{}; art < a; art++) {
      vector<string> &lista = artigos[art];

      for (ll au{}; au < lista.size(); au++) {
        for (ll outr{au + 1}; outr < lista.size(); outr++) {
          ll u = nome_no[lista[au]];
          ll v = nome_no[lista[outr]];

          adj[u].pb(v);
          adj[v].pb(u);
        }
      }
    }
    vll dist(autores.size(), -1);
    queue<ll> fila;
    if (origem != -1) {
      fila.push(origem);
      dist[origem] = 0;
      while (!fila.empty()) {
        ll v = fila.front();
        fila.pop();

        for (ll u : adj[v]) {
          if (dist[u] == -1) {
            dist[u] = dist[v] + 1;
            fila.push(u);
          }
        }
      }
    }

    cout << "Teste " << ++teste << '\n';
    for (auto &[nome, sobre] : autores) {
      string total = sobre + ' ' + nome;
      if (total == "P. Erdos")
        continue;

      cout << total << ": ";
      ll id = nome_no[total];

      if (dist[id] == -1)
        cout << "infinito\n";
      else
        cout << dist[id] << '\n';
    }
    cout << '\n';
  }

  return 0;
}
