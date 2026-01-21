#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll x; cin >> x;
  ll c{};
  while(x>0){
    if (x>=5){
      c++; x-=5;
    } else if (x>=4){
      c++; x-=4;
    } else if (x>=3){
      c++; x-=3;
    } else if (x>=2){
      c++; x-=2;
    } else {
      c++; x-=1;
    }
  }
  cout << c << '\n';

  return 0;
}

