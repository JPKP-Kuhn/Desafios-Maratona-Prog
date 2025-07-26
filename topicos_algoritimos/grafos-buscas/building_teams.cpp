#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays

vector<vll> adj(MAXN);
vll equipe(MAXN);

bool bfs(ll i){
  queue<ll> fila;
  fila.push(i);
  equipe[i] = 1;

  while(!fila.empty()){
    ll u = fila.front();
    fila.pop();

    for (ll v : adj[u]){
      if (equipe[v] == 0){
        equipe[v] = 3 - equipe[u];
        fila.push(v);
      } else if (equipe[v] == equipe[u]){
        return false;
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  cin >> n >> m;

  while(m--){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  fill(equipe.begin(), equipe.begin()+n, 0);

  for (ll i=0; i<n; i++){
    if (equipe[i] == 0){
      if (!bfs(i)){
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
  }

  for (ll i=0; i<n; i++){
    cout << equipe[i] << ' ';
  }
  cout << '\n';
  return 0;
}

