#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

int main() {
  _ ll a, b, c;
  cin >> a >> b >> c;
  ll x, y, z;
  cin >> x >> y >> z;

  if (a + b + c < x + y + z) {
    cout << "There are no miracles in life\n";
  } else {
    if (a < x) {
      if (c < (x - a)) {
        cout << "There are no miracles in life\n";
        return 0;
      } else {
        a = x;
        c -= (x - a);
        x = 0;
      }
    }
    if (b < y) {
      if (c < (y - b)) {
        cout << "There are no miracles in life\n";
        return 0;
      } else {
        b = y;
        c -= (y - b);
        y = 0;
      }
    }
    if (a == x) {
      a = 0;
      x = 0;
    }
    if (b == y) {
      b = 0;
      y = 0;
    }
    if (a > x) {
      z -= a - x;
      a = 0;
      x = 0;
    }

    if (b > y) {
      z -= b - y;
      b = 0;
      y = 0;
    }

    if (c >= z) {
      cout << "It is a kind of magic\n";
    } else {
      cout << "There are no miracles in life\n";
    }
  }

  return 0;
}
