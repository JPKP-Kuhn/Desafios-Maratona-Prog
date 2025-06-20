#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

ll n{};
set<ll> cores_subtree[MAXN];
vll nos[MAXN];
ll treeCores[MAXN];
ll distinct_colors[MAXN];

void dfs(ll no, ll pai){
  cores_subtree[no].insert(treeCores[no]);

  for (ll viz : nos[no]){
    if (viz == pai) continue;

    dfs(viz, no);

    if (cores_subtree[viz].size() > cores_subtree[no].size()){
      swap(cores_subtree[no], cores_subtree[viz]);
    }

    for (ll cor : cores_subtree[viz]) {
          cores_subtree[no].insert(cor);
    }

    distinct_colors[no] = cores_subtree[no].size();

  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (ll i=0; i<n; i++){
    cin >> treeCores[i];
  }
  for (ll j=0; j<n-1; j++){
    ll u, v;
    cin >> u >> v;
    u --; v--;
    nos[u].push_back(v);
    nos[v].push_back(u);
  }

  // Armazenar as cores distintas de cada nó
  dfs(0, -1);

  for (ll i = 0; i < n; i++){
    cout << (distinct_colors[i] != 0 ? distinct_colors[i] : 1) << ' ';
  }
  cout << '\n';

  return 0;
}

