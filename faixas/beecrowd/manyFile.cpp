#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

ll n;
vector<vll> adj;

ll digraph(ll v){
  vll degree(v, 0);
  queue<ll> q;
  vll level(v, 0);
  ll processed = 0;

  // Degree of vertices
  for (ll i = 0; i<v; i++){
    for (ll j : adj[i]){
      degree[j]++;
    }
  }
  // add degree 0 to the q
  for (ll i=0;i<v;i++){
    if (degree[i] == 0){
      q.push(i);
      level[i] = 1;
    }
  }

  ll maxTime{};
  while(!q.empty()){
    ll u = q.front();
    q.pop();
    processed++;
    maxTime = max(maxTime, level[u]);

    for (ll e : adj[u]){
      degree[e]--;
      if (degree[e] == 0){
        level[e] = level[u] + 1;
        q.push(e);
      }
    }
  }
  if (processed != v){ // If is a cicle, return -1;
    return -1;
  }
  return maxTime;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n){
    adj.clear();
    adj.resize(n);
    for (ll i=0; i<n; i++){
      ll m;
      cin >> m;
      for (ll j=0;j<m;j++){
        ll x;
        cin >> x;
        adj[i].push_back(--x);
      }
    }

    ll res = digraph(n);
    cout << res << '\n';
  }
  return 0;
}

