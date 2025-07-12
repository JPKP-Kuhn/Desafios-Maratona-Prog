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

  ll n;
  cin >> n;
  string s;
  ll total = 101;
  bool longo = false;
  for(ll j=0; j<n; j++){
    char c; ll num;
    cin >> c >> num;
    if (!longo){
      total-=num;
    }
    if (total <= 0){
      longo = true;
    }else{
      s += string(num, c);
    }
  }

  if (longo){
    cout << "Too Long\n";
  } else {
    cout << s << '\n';
  }

  return 0;
}

