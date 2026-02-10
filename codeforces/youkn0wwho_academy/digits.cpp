#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T; cin >> T;
  while(T--){
    ll x; cin >> x;
    if (x==0){
      cout << 0 << '\n';
    } else{
      while(x>0){
        ll d = x%10;
        x/=10;
        cout << d << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}

