#include <bits/stdc++.h>
#include <cctype>
#include <sstream>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays

ll n, m;
vll nx = {0, 1, 1, 1, 0, -1, -1, -1};
vll ny = {1, 1, 0, -1, -1, -1, 0, 1};
ll dfs (ll r, ll c, vector<string> &mapa, vector<vector<bool>> &visited){
  if (r < 0 || r >= n || c < 0 || c >= m) return 0;
  if (visited[r][c] || mapa[r][c] != 'W') return 0;
  visited[r][c] = true;
  ll area = 1;
  for (ll d=0; d<8; d++){
    area += dfs(r+nx[d], c+ny[d], mapa, visited);
  }
  return area;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  string linha;
  cin >> t;
  cin.ignore();
  getline(cin, linha);
  while(t--){
    vector<string> mapa;
    vpll pedidos;

    while(getline(cin, linha)){
      if (linha.empty()) break;
      if (isdigit(linha[0])) break;
      mapa.push_back(linha);
    }

    n = mapa.size();
    m = mapa[0].size();

    if (!linha.empty() && isdigit(linha[0])){
      stringstream ss(linha);
      ll x, y;
      ss >> x >> y;
      pedidos.emplace_back(x-1, y-1);
    }

    while(getline(cin, linha)){
      if (linha.empty()) break;
      stringstream ss(linha);
      ll x, y;
      ss >> x >> y;
      pedidos.emplace_back(x-1, y-1);
    }

    for (auto [r, c] : pedidos){
      vector<vector<bool>> visited(n, vector<bool>(m, false));
      cout << dfs(r, c, mapa, visited) << '\n';
    }

    if (t>0) cout << '\n';
  }

  return 0;
}

