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
  string s, t;
  cin >> s >> t;
  bool achou = true;

  for (ll c = 1; c<s.length(); c++){
    if (s[c] >= 'A' && s[c] <= 'Z'){
      if (t.find(s[c-1]) == string::npos){
        achou = false;
      }
    }
  }
  cout << (achou ? "Yes\n" : "No\n");

  return 0;
}

