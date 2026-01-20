#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e6;
const ll MINF = -1e6;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  ll teste{};
  while(cin >> n && n){
    ll mx{MINF}, my{MINF}, mu{MINF}, mv{MINF}, lx{INF}, ly{INF}, lu{INF}, lv{INF};
    ll x, y, u, v;
    for (ll i{}; i<n; i++){
      cin >> x >> y >> u >> v;

      mx = max(mx, x); lx = min(lx, x);
      my = max(my, y); ly = min(ly, y);
      mu = max(mu, u); lu = min(lu, u);
      mv = max(mv, v); lv = min(lv, v);
    }

    cout << "Teste " << ++teste << '\n';
    if (mx > lu || ly < mv){
      cout << "nenhum\n";
    } else {
      cout << mx << ' ' << ly << ' ' << lu << ' ' << mv << '\n';
    }

    cout << '\n';
  }
  return 0;
}

