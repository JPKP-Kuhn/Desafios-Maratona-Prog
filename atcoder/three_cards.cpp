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
  ll total{};

  for (ll i=1; i<=n; i++){
    for (ll j=1; j<=n; j++){
      ll c = k - i - j;
      if (c >= 1 && c<=n) total++;
    }
  }
  cout << total << '\n';
  return 0;
}

