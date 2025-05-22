#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll pupils, friends;
  cin >> pupils >> friends;
  vector<vector<ll>> adj(pupils+1);
  queue<ll> q;
  vector<ll> pai(pupils+1, -1);
  vector<bool> usado(pupils+1, false);

  for (int i = 0; i < friends; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cout << "Grafo:\n";
    for (int u = 0; u < pupils+1; u++) {
        cout << u << ": ";
        for (int v : adj[u])
            cout << v << ' ';
        cout << '\n';
    }

  q.push(1);
  usado[1] = true;
  vector<ll> time1;
  time1.push_back(1);
  cout << 1 << ' ';

  while (!q.empty()) {
    int n = q.front();
    q.pop();

    for (int u : adj[n]) {
      if (!usado[u]){
        // Para cada ligação u dentro n, eles não podem estar dentro do mesmo time
      }
    }
  }


  return 0;
}

