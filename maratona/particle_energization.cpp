#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll maxn = pow(10, 5) + 10;

ll gcd(ll a, ll b) {
  ll res = min(a, b);

  while (res > 1) {
    if ( a % res == 0 and b % res == 0) break;
    res--;
  }

  return res;
}

int main() {
  // Código com TLE, precisa de algum jeito ter uma previsão do valor; k pode ser pow(10, 9)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll x = 1;
  ll y, k;
  cin >> y >> k;

  for (ll i = 0; i<k; i++) {
    x += gcd(x, y);
  }

  cout << x << endl;


  return 0;
}

