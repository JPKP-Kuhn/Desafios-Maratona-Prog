#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll p; cin >> p;
  bool f=true;
  for (ll i=2; i<(round(sqrt(p))+1); i++){
    if (p%i==0){
      f=false; break;
    }
  }
  if (f) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}

