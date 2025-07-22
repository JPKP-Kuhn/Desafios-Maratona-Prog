#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll p, r, g, x;
  cin >> p >> r >> g >> x;
  ll goals = g * x;
  ll tot = (goals <= r ? p * goals : p * r);

  cout << tot << '\n';

  return 0;
}

