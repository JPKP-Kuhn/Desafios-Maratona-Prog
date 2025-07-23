#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll k;
  cin >> k;
  double um = 1.0/6.0;

  vector<tuple<ll, ll, ll>> n;
  for (ll i=1; i<=6; i++){
    for (ll j=1; j<=6; j++){
      ll c = k-i-j;
      if (c > 0 && c <= 6){
        n.push_back({i, j, c});
      }
    }
  }

  double p = pow(um, 3) * n.size();

  cout << fixed << setprecision(12) << p << '\n';

  return 0;
}

