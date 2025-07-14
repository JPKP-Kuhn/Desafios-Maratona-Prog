#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  ll n;
  cin >> s >> n;
  for (ll i=0; i<n; i++){
    string p;
    cin >> p;
    bool f = true;
    if (p.length() < s.length() || p.length() % s.length() != 0){
      cout << "No\n";
      f = false;
    } else {
      for (ll j=0; j<p.length(); j++){
        if (p[j] != s[j%s.length()]){
          cout << "No\n";
          f = false;
          break;
        }
      }
    }
    if (f) cout << "Yes\n";
  }

  return 0;
}

