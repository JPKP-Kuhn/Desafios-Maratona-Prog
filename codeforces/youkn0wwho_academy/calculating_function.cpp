#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vpll = vector<pair<ll, ll>>;

// f(n) = (-1)^n * n
// n ímpar é -, par é +
// -1, 1, -2, 2

int main() {
  _ ll n;
  cin >> n;

  double q = n / 2.0;

  ll ans = ceil(q);
  cout << (n & 1 ? -ans : ans) << '\n';
  return 0;
}
