#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll c{}, n; cin >> n;
  vb learn(n+1, false);
  vpll prere(n+1);
  vector<vll> adj(n+1);
  queue<ll>q;

  for (ll i=1; i<=n; i++){
    ll a, b; cin >> a >> b;

    prere[i] = {a, b};
    if (a == 0 && b == 0){
      learn[i] = true;
      q.push(i);
      c++;
    } else {
      adj[a].push_back(i);
      adj[b].push_back(i);
    }
  }

  return 0;
}

