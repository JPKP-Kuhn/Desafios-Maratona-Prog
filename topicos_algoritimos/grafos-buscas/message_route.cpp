#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  cin >> n >> m;
  vector<vll> adj(n);
  vector<bool> used(n);
  vll pai(n);

  for (ll i=0; i<m; i++){
    ll x, y;
    cin >> x >> y;
    x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  queue<ll> fila;
  fila.push(0);
  pai[0] = -1;
  used[0] = true;

  bool achou = false;

  while(!fila.empty()){
    ll v = fila.front();
    fila.pop();

    for (ll u : adj[v]){
      if (!used[u]){
        used[u] = true;
        fila.push(u);
        pai[u] = v;
        if (u == n-1){
          achou = true;
        }
      }
    }
  }

  if (achou){
    vll route;
    for (ll v= n-1; v != -1; v = pai[v])
      route.push_back(v+1);
    reverse(route.begin(), route.end());

    cout << route.size() << '\n';
    for (size_t i = 0; i < route.size(); ++i) {
      if (i > 0) cout << ' ';
      cout << route[i];
    }
    cout << '\n';
  } else {
    cout << "IMPOSSIBLE\n";
  }

  return 0;
}

