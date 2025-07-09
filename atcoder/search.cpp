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
  ll n, s;
  cin >> n >> s;
  vll num(n);
  for (ll &x : num) cin >> x;
  ll c = count(num.begin(), num.end(), s);
  cout << (c > 0 ? "Yes\n" : "No\n");
  return 0;
}

