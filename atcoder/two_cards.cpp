#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k;
  cin >> n >> k;
  vll p(n);
  vll q(n);

  for (ll i=0; i<n; i++){
    cin >> p[i];
  }
  for (ll i=0; i<n; i++){
    cin >> q[i];
  }

  for (ll i=0; i<n; i++){
    ll val = k;
    val-=p[i];
    for (ll j=0; j<n; j++){
      if (val - q[j] == 0){
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";

  return 0;
}

