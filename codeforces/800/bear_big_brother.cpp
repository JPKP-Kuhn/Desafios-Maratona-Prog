#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b; cin >> a >> b;
  ll c{};
  while(a<=b){
    a*=3; b*=2; c++;
  }
  cout << c << '\n';

  return 0;
}

