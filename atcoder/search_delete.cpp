#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  vll a(n), b(m);
  for (ll &x : a) cin >> x;
  for (ll &y : b) cin >> y;

  for (ll i=0; i<m; i++){
    auto it = find(a.begin(), a.end(), b[i]);
    if (it != a.end()){
      a.erase(it);
    }
  }
  for (ll i : a){
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}

