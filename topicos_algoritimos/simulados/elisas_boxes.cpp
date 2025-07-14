#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  vll box(n);
  for (ll &x : box) cin >> x;
  for (ll i=0; i<n; i++){
    if (box[i] >= m){
      cout << i+1 << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';

  return 0;
}

