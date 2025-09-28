#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll n; cin >> n;
    bool cortar = true;
    vll pares, impar;
    for (ll i=0; i<n; i++){
      ll x; cin >> x;

      if (x%2==0) pares.push_back(x);
      else impar.push_back(x);
    }

    if (impar.empty()) cout << 0 << '\n';
    else {
      sort(impar.begin(), impar.end());
      bool primeira = true;
      ll soma{};

      ll l=0, r=(int)impar.size()-1;
      while(l<=r){
        if (cortar){
          soma+=impar[r];
          if (primeira){
            soma += accumulate(pares.begin(), pares.end(), 0LL);
            primeira=false;
          }
          r--;
        } else{
          l++;
        }
        cortar = !cortar;
      }

      cout << soma << '\n';
    }
  }

  return 0;
}

