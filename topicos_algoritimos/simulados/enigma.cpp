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

  ll x, y;
  cin >> x >> y;
  ll a, b;
  // x = a + b 
  // y = abs(a - b)

  a = (x+y)/2;
  b = x-a;
  cout << a << ' ' << b << '\n';
  return 0;
}

