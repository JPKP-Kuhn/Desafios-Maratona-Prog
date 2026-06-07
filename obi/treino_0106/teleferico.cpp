#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

int main() {
  _ ll c, a;
  cin >> c >> a;

  if (a < c) {
    cout << 1 << '\n';
  } else {
    cout << ceil((double)a / (double)(c - 1)) << '\n';
  }

  return 0;
}
