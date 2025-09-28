#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while(t--){
    ll a, x, y;
    cin >> a >> x >> y;

    if (a >= min(x, y) && a <= max(x, y)){
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }

  return 0;
}

