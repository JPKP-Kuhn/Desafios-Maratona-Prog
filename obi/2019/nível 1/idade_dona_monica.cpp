#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll m, a, b;
  cin >> m >> a >> b;
  // a + b + x == m
  ll x = m - a - b;
  cout << max({x, a, b}) << '\n';

  return 0;
}

