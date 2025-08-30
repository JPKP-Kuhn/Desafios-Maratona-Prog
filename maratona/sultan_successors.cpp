#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll k; cin >> k;
  while(k--){
    vector<vll> chess(8, vll(8));
    for (ll i=0; i<8; i++){
      for (ll j=0; j<8; j++){
        cin >> chess[i][j];
      }
    }
  }

  return 0;
}

