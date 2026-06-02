#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

int main() {
  _ string a, b;
  while (getline(cin, a) && getline(cin, b)) {
    ll dp[51][51] = {};
    ll maior{};

    for (ll i{1}; i <= a.length(); i++) {
      for (ll j{1}; j <= b.length(); j++) {
        if (a[i - 1] == b[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          maior = max(maior, dp[i][j]);
        }
      }
    }
    cout << maior << '\n';
  }

  return 0;
}
