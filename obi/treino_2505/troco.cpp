#include <bits/stdc++.h>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;

int main() {
  _ ll v, n;
  cin >> v >> n;
  vb dp(v + 1, false);
  vll num(n);
  for (ll &x : num)
    cin >> x;

  dp[0] = true;

  for (ll c : num) {
    for (ll s = v; s >= c; s--) {
      dp[s] = dp[s] || dp[s - c];
    }
  }

  cout << (dp[v] ? "S\n" : "N\n");

  return 0;
}
