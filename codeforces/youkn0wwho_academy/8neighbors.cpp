#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m; cin >> n >> m;
  vector<string> mat(n);
  for (string &p : mat) cin >> p;
  ll x,y; cin >> x >> y; x--; y--;

  vll nx = {0, 1, 1, 1, 0, -1, -1, -1};
  vll ny = {1, 1, 0, -1, -1, -1, 0, 1};

  bool f = true;
  for (ll d{}; d<nx.size(); d++){
    ll i = x+nx[d];
    ll j = y+ny[d];

    if (i>=0 && i<n && j>=0 && j<m){
      if (mat[i][j] != 'x') {
        f=false; break;
      }
    }
  }
  cout << (f ? "yes" : "no") << '\n';

  return 0;
}

