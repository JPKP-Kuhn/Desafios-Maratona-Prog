#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool eh_primo(ll x){
  if (x<=1) return false;

  for (ll i=2; i<round(sqrt(x))+1; ++i){
    if (x%i==0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll x; cin >> x;

  if (eh_primo(x)){
    cout << "S\n";
  } else {
    cout <<"N\n";
  }

  return 0;
}

