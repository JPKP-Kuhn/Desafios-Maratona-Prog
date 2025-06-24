#include <bits/stdc++.h>
#include <ios>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

ll t, n, m, a, b;

bool cicle(ll v, vector<vll>& adj){
  vll degree(v, 0);
  queue<ll> q;
  ll visited{};

  // Degree of vertices
  for (ll i = 0; i<v; i++){
    for (ll j : adj[i]){
      degree[j]++;
       cout << "Nó " << j << " tem agora grau " << degree[j] << '\n';
    }
  }
  // add degree 0 to the q
  for (ll i=0;i<v;i++){
    if (degree[i] == 0){
      q.push(i);
    }
  }

  cout << "Fila:\n";
  while(!q.empty()){
    ll u = q.front();
    cout << "Nó " << u << " foi visitado" << '\n';
    q.pop();
    visited++;

    cout << "Agora, para cada nó no nó " << u << '\n';
    for (ll e : adj[u]){
      degree[e]--;
      cout << "Nó " << e << " tem grau " << degree[e] << '\n';
      if (degree[e] == 0){
        q.push(e);
      }
    }
  }
  cout << "Total visitados: " << visited << '\n';
  return visited != v;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  while (t--){
    cin >> n >> m; // Doc e dependencias

    vector<vll> adj(n);
    for (ll i=0;i<m;i++){
      cin >> a >> b;
      a--; b--; 
      adj[a].push_back(b);
    }

    bool ciclo = cicle(n, adj);
    cout << (ciclo ? "SIM\n" : "NAO\n");

  }

  return 0;
}

