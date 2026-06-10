#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;

int main() {
  _ ll n, m;
  cin >> n >> m;
  ll r = m - n;
  cout << m + r << '\n';

  return 0;
}
