#include <bits/stdc++.h>
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
  string s; cin >> s;
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  for (char c : s){
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y') s.erase(c);
  }
  cout << s << '\n';

  return 0;
}

