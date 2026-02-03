#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct point ;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  ll maior{};
  while(n--){
    ll x; cin >> x;
    maior=max(x, maior);
  }
  cout << maior << '\n';

  return 0;
}

