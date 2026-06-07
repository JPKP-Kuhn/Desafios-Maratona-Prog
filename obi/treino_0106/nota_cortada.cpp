#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

ll compri = 160;
ll alt = 70;
ll tot = 160 * 70;

double area(ll b, ll B) { return (double)(b + B) * alt / 2.0; }

int main() {
  _ ll b, t;
  cin >> b >> t;

  double esq = area(b, t);
  double dir = tot - esq;

  if (esq > dir) {
    cout << 1;
  } else if (esq < dir) {
    cout << 2;
  } else {
    cout << 0;
  }
  cout << '\n';

  return 0;
}
