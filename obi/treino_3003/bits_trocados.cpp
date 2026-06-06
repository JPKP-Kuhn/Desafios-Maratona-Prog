#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

int main() {
  _ ll v;
  ll caso{};
  while (cin >> v && v) {
    ll c{}, d{}, cinco{}, um{};

    while (v > 0) {
      if (v >= 50) {
        c++;
        v -= 50;
      } else if (v >= 10) {
        d++;
        v -= 10;
      } else if (v >= 5) {
        cinco++;
        v -= 5;
      } else if (v >= 1) {
        um++;
        v -= 1;
      }
    }

    cout << "Teste " << ++caso << '\n';
    cout << c << ' ' << d << ' ' << cinco << ' ' << um << "\n\n";
  }

  return 0;
}
