#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T; cin >> T;
  while(T--){
    ll x, y; cin >> x >> y;
    ll a=min(x,y), b=max(x,y);
    ll sum{};
    for (ll i=a+1; i<b; i++){
      if (i%2==1) sum+=i;
    }
    cout << sum << '\n';

  }

  return 0;
}

