#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  pair<ll, ll> n;
  cin >> s;
  bool primeiro, segundo;
  primeiro = true;
  for (ll i=0; i<s.length(); i++){
    if (s[i] == '#'){
      if (primeiro){
        n.first = i;
        primeiro = false;
        segundo = true;
        continue;
      }
      if (segundo){
        n.second = i;
        primeiro = true;
        segundo = false;
        cout << n.first+1 << ',' << n.second+1 << '\n';
      }
    }
  }

  return 0;
}

