#include <bits/stdc++.h>
#include <cctype>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo
const ll MOD = 1e9+7;    // Valor comum para aritmética modular, números muito grandes

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b; cin >> a >> b;
  transform(a.begin(), a.end(), a.begin(), ::tolower);
  transform(b.begin(), b.end(), b.begin(), ::tolower);

  if (a == b) cout << 0 << '\n';
  else if (a < b) cout << -1 << '\n';
  else cout << 1 << '\n';

  return 0;
}

