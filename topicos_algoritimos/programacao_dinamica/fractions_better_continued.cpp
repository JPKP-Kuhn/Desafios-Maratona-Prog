#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  ll a=1, b=2;
  for (ll i=1; i<n; i++){
    ll temp = b;
    b += a;
    a = temp;
  }
  cout << a << '\n';

  return 0;
}

