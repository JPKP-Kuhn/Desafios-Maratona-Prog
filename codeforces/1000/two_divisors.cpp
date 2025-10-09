#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while(t--){
    ll a, b; cin >> a >> b;

    if (b%a == 0){
      // b = a * p, p is prime
      // x = b * p = b * b/a
      cout << b*b/a << '\n';
    } else {
      // b = x/p and a = x/q, p and q are primes
      // gcd(a, b) = x/(p*q); x = b * p = b * a/(gcd(a, b))
      cout << b * a/(gcd(a, b)) << '\n';
    }
  }

  return 0;
}

