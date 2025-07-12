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

  ll n, macha, marce;
  cin >> n >> macha >> marce;
  vll stairs(n);
  for (ll &x : stairs) cin >> x;
  ll k;
  cin >> k; k--;
  for (ll i=0; i<=k; i++){
    marce+=stairs[i];
  }

  bool t = false;
  ll idx{};
  for (ll i=0; i<n; i++){
    if (i == k){
      macha+=stairs[k];
    }else{
      macha+=stairs[i];
      if (macha >= marce){
        t = true;
        idx = i+1;
        break;
      }
    }
  }

  if (t){
    cout << "SIM\n";
    cout << idx << '\n';
  }else {
    cout << "NAO\n";
  }

  return 0;
}

