#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

int main() {
  _ ll n;
  cin >> n;

  ll sq = ceil(sqrt(n));

  for (ll i{2}; i <= sq; i++) {
    if (n % i == 0) {
      cout << "S\n";
      return 0;
    }
  }
  cout << "N\n";

  return 0;
}
