#include <algorithm>
#include <bits/stdc++.h>
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
    string n;
    cin >> n;
    ll m = count(n.begin(), n.end(), '-');
    if (m == 0){
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }

  return 0;
}

