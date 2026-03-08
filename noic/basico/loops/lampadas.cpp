#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  bool a=false, b=false;
  while(n--){
    ll x; cin >> x;
    if (x==1){
      a=!a;
    } else{
      a=!a; b=!b;
    }
  }
  if (a) cout << 1 << '\n';
  else cout << 0 << '\n';

  if (b) cout << 1 << '\n';
  else cout << 0 << '\n';

  return 0;
}

