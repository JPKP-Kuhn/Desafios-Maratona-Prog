#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll maxn = pow(10, 5) + 10;

/*
y, k

1, 2, 3, ... p, 2p, 3p, 4p, ... p², 2p², ...
1, 2, 3, ... p, 2p, 3p, 4p, ... p², (p+1)p², ... p2 * p, 2 * p2 * p1...

O processo pode ser pulado de primo em primo
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll y, k;
  cin >> y >> k;

  vll p;
  for (ll i = 2; i*i <= y; i++){
    while (y % i == 0) {
      p.push_back(i);
      y /= i;
    }
  }
  if (y > 1) {
    p.push_back(y);
  }

  ll resp = 1;
  for (ll pr : p) {
    if (k > pr - 1) {
        resp *= pr;
      k -= pr - 1;
    } else {
      resp *= k + 1;
      k = 0;
      break;
    }
  }
  resp *= k + 1;
  cout << resp << '\n';

  return 0;
}

