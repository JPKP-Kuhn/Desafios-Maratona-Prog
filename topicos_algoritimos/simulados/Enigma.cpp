#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string msg, crib;
  cin >> msg >> crib;
  ll c{};
  for (ll i=0; i<msg.length(); i++){
    string s{};
    for (ll j=0; j<crib.length(); j++){
      if (i+j >= msg.length()) break;
      if (msg[i+j] == crib[j]){
        break;
      } 
      s+=crib[j];
    }
    if (s.length() == crib.length()){
      c++;
    }
  }
  cout << c << '\n';

  return 0;
}

