#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vll p(n), a(n), b(n);
  for (ll i=0; i<n; i++){
    cin >> p[i] >> a[i] >> b[i];
  }
  ll q;
  cin >> q;
  while(q--){
    ll x;
    cin >> x;
    for (ll i=0; i<n; i++){
      if (p[i] >= x){
        x+=a[i];
      } else{
        if (x<b[i]) x=0;
        else x-=b[i];
      }
    }
    cout << x << '\n';
  }

  return 0;
}

